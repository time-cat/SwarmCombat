from setuptools import find_packages
from setuptools import setup

setup(
    name='fwp_planner',
    version='0.1.0',
    packages=find_packages(
        include=('fwp_planner', 'fwp_planner.*')),
)
