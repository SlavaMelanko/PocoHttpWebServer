# PocoHttpWebServer

This is a test project to find and check tools/packages/services which improve the quality, readability of code and reliable of the future product at all.

[![GitHub version](https://badge.fury.io/gh/SMelanko%2FPocoHttpWebServer.svg)](https://badge.fury.io/gh/SMelanko%2FPocoHttpWebServer)
[![Build Status: Linux, OSX](https://travis-ci.org/SMelanko/PocoHttpWebServer.svg?branch=master)](https://travis-ci.org/SMelanko/PocoHttpWebServer)
[![Build Status: Windows](https://ci.appveyor.com/api/projects/status/github/SMelanko/PocoHttpWebServer?branch=master&svg=true)](https://ci.appveyor.com/project/SMelanko/PocoHttpWebServer)
[![codecov](https://codecov.io/gh/SMelanko/PocoHttpWebServer/branch/master/graph/badge.svg)](https://codecov.io/gh/SMelanko/PocoHttpWebServer)
[![Coverage Status](https://coveralls.io/repos/github/SMelanko/PocoHttpWebServer/badge.svg?branch=master)](https://coveralls.io/github/SMelanko/PocoHttpWebServer?branch=master)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/f922034805584ab0be793eb87b13e1ab)](https://www.codacy.com/app/SMelanko/PocoHttpWebServer?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SMelanko/PocoHttpWebServer&amp;utm_campaign=Badge_Grade)
<a href="https://scan.coverity.com/projects/smelanko-pocohttpwebserver">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/15851/badge.svg"/>
</a>

[CppCon 2017: Rian Quinn “A Test a Day Keeps Your Manager Away!”](https://youtu.be/KdJhQuycD78)

### Main Concepts

- The Evils of Duplication - do not repeat yourself (DRY)
- Orthogonality - make modules less cohesion
- Reversibility
- Respect all people who are or will be involved into project

### Major Technologies

- [C++14](https://isocpp.org/wiki/faq/cpp14)
- [CMake](https://cmake.org/) + [cotire](https://github.com/sakra/cotire) + [cmakelint](https://github.com/richq/cmake-lint)
- [Conan](https://www.conan.io/)
- [Git](https://git-scm.com/) + [SmartGit](https://www.syntevo.com/smartgit/)

### Integrated Development Environments (IDE)

- Visual Studio Community 2017
- CLion
- Xcode
- Qt Creator

### Continuous Integration Services

- [Travis CI](https://travis-ci.org) is a hosted, distributed continuous integration service used to build and test software projects hosted at GitHub.
- [AppVeyor](https://www.appveyor.com) is a hosted, distributed continuous integration service used to build and test projects hosted on GitHub on a Microsoft Windows virtual machine.

### Code Coverage Tools

- [Code Coverage](https://codecov.io) is a measurement used to express which lines of code were executed by a test suite.
- [Coveralls](https://coveralls.io) is a web service to help you track your code coverage over time, and ensure that all your new code is fully covered.

### C++ Analysis Tools

- [Codacy](https://app.codacy.com) is an automated code review platform.
- [Coverity](https://scan.coverity.com/dashboard) is a brand of software development products from Synopsys, consisting primarily of static code analysis and dynamic code analysis tools.
- [CppCheck](http://cppcheck.sourceforge.net) is an analysis tool for C/C++ code. It detects the types of bugs that the compilers normally fail to detect.
- [Clang-Tidy](http://apt.llvm.org/) is a clang-based C++ “linter” tool. Its purpose is to provide an extensible framework for diagnosing and fixing typical programming errors, like style violations, interface misuse, or bugs that can be deduced via static analysis.
``` bash
TODO: Move to wiki
sudo apt-rm-repository "deb http://apt.llvm.org/artful/ llvm-toolchain-artful-6.0 main"
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add -
sudo apt-get install clang-6.0 lldb-6.0 clang-tools-6.0
```
- [Valgrind](http://valgrind.org) is a programming tool for memory debugging, memory leak detection, and profiling.
- [Google Sanitizers](https://github.com/google/sanitizers) is another analysis tool for C/C++ code which is based on:
  * AddressSanitizer
  * MemorySanitizer
  * ThreadSanitizer

### Continuous Delivery Tools

- [Docker](https://www.docker.com/) is a tool designed to make it easier to create, deploy, and run applications by using containers.

### Specification

- OpenAPI + Swagger (tools for implementing the specification)

### Others

- [draw.io](https://www.draw.io/) is a diagramming tool which helps to create flowcharts, process diagrams, org charts, UML, ER diagrams, network diagrams and much more.
