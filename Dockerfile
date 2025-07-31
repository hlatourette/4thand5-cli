FROM gcc:12.3 AS build
RUN apt-get update && apt-get install -y \
    catch2 \
    cmake && \
    apt-get autoremove && \
    apt-get -y clean && \
    rm -rf /var/lib/apt/lists/*
COPY . /usr/local/src/templateapp
WORKDIR /usr/local/src/templateapp
RUN make build && \
    make test && \
    make package

FROM scratch AS build-export
COPY --from=build /usr/local/src/templateapp/build/templateapp-Linux.deb /
WORKDIR /

FROM ubuntu:latest AS test
COPY --from=build /usr/local/src/templateapp/build/tests/integration/templateapp.i.t /usr/local/bin
WORKDIR /usr/local/bin
ENTRYPOINT [ "/usr/local/bin/templateapp.i.t" ]

FROM ubuntu:latest AS run
COPY --from=build /usr/local/src/templateapp/build/templateapp-Linux.deb /usr/local/bin
WORKDIR /usr/local/bin
RUN dpkg -i templateapp-Linux.deb
ENTRYPOINT [ "/usr/bin/templateapp.sh" ]
