FROM gcc:12.3 AS build
RUN apt-get update && apt-get install -y \
    catch2 \
    cmake && \
    apt-get autoremove && \
    apt-get -y clean && \
    rm -rf /var/lib/apt/lists/*
COPY . /usr/local/src/4thand5-cli
WORKDIR /usr/local/src/4thand5-cli
RUN make build && \
    make test && \
    make package

FROM scratch AS build-export
COPY --from=build /usr/local/src/4thand5-cli/build/4thand5-cli-Linux.deb /
WORKDIR /

FROM ubuntu:latest AS test
COPY --from=build /usr/local/src/4thand5-cli/build/tests/integration/4thand5.i.t /usr/local/bin
WORKDIR /usr/local/bin
ENTRYPOINT [ "/usr/local/bin/4thand5.i.t" ]

FROM ubuntu:latest AS run
COPY --from=build /usr/local/src/4thand5-cli/build/4thand5-cli-Linux.deb /usr/local/bin
WORKDIR /usr/local/bin
RUN dpkg -i 4thand5-cli-Linux.deb
ENTRYPOINT [ "/usr/bin/4thand5" ]

