from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

ext_modules = [
    Pybind11Extension("example", ["example.cpp"]),
]

setup(name="_stacktrace", version="1.0", ext_modules=ext_modules)
