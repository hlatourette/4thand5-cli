# template-app-cpp
Template C/C++ application

## Build
```
docker build --target=build-export --output type=local,dest=./output .
```

## Test

### Unit
```
docker build --target=build -t templateapp .
```

### Integration
```
docker build --target=test -t templateapp .
docker run -it --rm templateapp
```

## Run
```
docker build --target=run -t templateapp .
docker run -it --rm templateapp
```
