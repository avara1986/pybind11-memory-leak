#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

using namespace std;
using namespace pybind11::literals;
namespace py = pybind11;

struct TaintRange
{
    long start = 0;
    long length = 0;

    TaintRange(long start, long length)
      : start(start)
      , length(length)
    {}
};

using TaintRangePtr = shared_ptr<TaintRange>;
using TaintRangeRefs = vector<TaintRangePtr>;

TaintRangeRefs
create_ranges()
{
    TaintRangeRefs ranges_;
    ranges_.reserve(1);
    ranges_.emplace_back(make_shared<TaintRange>(0, 1));
    return ranges_;
}

TaintRangeRefs
get_ranges(py::object& str)
{
    TaintRangeRefs ranges_;
    ranges_.reserve(1);
    ranges_.emplace_back(make_shared<TaintRange>(0, 1));
    return ranges_;
}

void
set_ranges(py::object& str, const TaintRangeRefs& ranges)
{
    auto result = ranges;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("set_ranges", &set_ranges, "str"_a, "ranges"_a);
    //m.def("create_ranges", &create_ranges,  py::return_value_policy::take_ownership);
    m.def("get_ranges",
          &get_ranges,
          "string_input"_a,
          py::return_value_policy::take_ownership);
    py::class_<TaintRange, shared_ptr<TaintRange>>(m, "TaintRange_")
      // Normal constructor disabled on the Python side, see above
      .def_readonly("start", &TaintRange::start)
      .def_readonly("length", &TaintRange::length);
}