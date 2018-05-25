# Use an official and the latest GCC image.
FROM gcc:7

# Set the author field of the generated image.
LABEL maintainer="Slava Melanko"

# Install the latest CMake.
ADD https://cmake.org/files/v3.10/cmake-3.10.0-Linux-x86_64.sh /cmake-3.10.0-Linux-x86_64.sh
RUN mkdir /opt/cmake
RUN sh /cmake-3.10.0-Linux-x86_64.sh --prefix=/opt/cmake --skip-license
RUN ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake
RUN rm /cmake-3.10.0-Linux-x86_64.sh
RUN cmake --version

# Update system to the newest versions of packages and their dependencies
# and install additional packages.
RUN apt-get update && apt-get install -y --no-install-recommends mc python-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install Python package manager.
ADD https://bootstrap.pypa.io/get-pip.py /get-pip.py
RUN python get-pip.py
RUN rm /get-pip.py
RUN pip install -q -U pip

# Install the latest Conan.
RUN pip install -q --no-cache-dir conan
RUN conan user
RUN conan --version

# Make port 80 available to the world outside this container.
EXPOSE 80

# Set the working directory.
WORKDIR /projects
# Copy the github repo into the container at $WORKDIR directory.
RUN git clone https://github.com/SMelanko/PocoHttpWebServer.git
# Build the project.
WORKDIR /projects/PocoHttpWebServer/build
RUN conan install .. --build missing -s build_type=Release -s compiler.libcxx=libstdc++11
RUN cmake .. -DCMAKE_BUILD_TYPE:STRING=Release
RUN cmake --build . --config Release

# Run HTTP WEB server.
WORKDIR /projects/PocoHttpWebServer/build/bin

CMD ["./server"]
