# Check allocations with memray

```
python3.11 setup.py build_ext --inplace
export PYTHONMALLOC=malloc
python3.11 main.py
python3.11 -m memray run --trace-python-allocators --native -o lel.bin -f main.py
python3.11 -m memray flamegraph lel.bin --leaks -f
```

# Check allocations with Python debug

```
docker build . -f Dockerfile_Python311Debug -t python_311_debug
docker run --rm -it -v ${PWD}:/test python_311_debug
cd /test && python3.11 setup.py build_ext --inplace && python3.11 memray_references.py
```