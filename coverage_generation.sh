#!/bin/bash
# before use this script,you should run the program
# ubuntu 20.04
# sudo apt-get install lcov
# sudo apt-get install gcovr
lcov --directory . --directory src --directory test --capture --output-file ./coverage/coverage.info
lcov --remove ./coverage/coverage.info '/usr/*' '*/googletest/*' --output-file ./coverage/coverage.info
genhtml ./coverage/coverage.info -o ./coverage/coverage_report