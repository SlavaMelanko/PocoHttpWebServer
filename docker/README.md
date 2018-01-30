//
// Build
//

$ sudo docker image build -t gcc-dev .

$ sudo docker image ls

REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE

gcc-dev             latest              0f17df913f7c        11 minutes ago      1.92GB

//
// Run
//

$ sudo docker run -d -p 4000:9980 0f17df913f7c

//
// Test
//

http://localhost:4000/

