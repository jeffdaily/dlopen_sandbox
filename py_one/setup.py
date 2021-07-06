from glob import glob
from setuptools import setup
try:
    from pybind11.setup_helpers import Pybind11Extension
except ImportError:
    from setuptools import Extension as Pybind11Extension

ext_modules = [
    Pybind11Extension(
        "one_caller",
        sources = sorted(glob("src/*.cpp")),  # Sort source files for reproducibility
        libraries = ["racecar_runtime"],
        library_dirs = ["/usr/local/lib"]
    ),
]

setup(
    name="one",
    version="1.0",
    author="Nobody",
    author_email="nobody@nobody.com",
    ext_modules=ext_modules,
    setup_requires=["pybind11"]
)
