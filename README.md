# 4thand5-cli
College Football Game Feed

```
+---------+----+----V----+3---V----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+---------+
|         |    |   1|0   |   2|0   |   3|0   |   4|0   |   5|0   |   4|0   |   3|0   |   2|0   |   1|0   |    |         |
|         |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |         |
|   ARK   |    |    |    |*-------->    |    |    |    |   ARK   |    |    |    |    |    |    |    |    |    |   MIZ   |
|         |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |         |
|         |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |         |
+---------+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+---------+
```

## Build
```
docker build --target=build-export --output type=local,dest=./output .
```

## Test

### Unit
```
docker build --target=build -t 4thand5-cli .
```

### Integration
```
docker build --target=test -t 4thand5-cli .
docker run -it --rm 4thand5-cli
```

## Run
```
docker build --target=run -t 4thand5-cli .
docker run -it --rm 4thand5-cli
```

