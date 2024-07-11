FROM alpine as build-env

RUN apk add --no-cache build-base procps

WORKDIR /app
COPY . .

# Compile the binaries
RUN gcc -o zombie zombie.c


FROM alpine
COPY --from=build-env /app/zombie /app/zombie
WORKDIR /app

CMD ["/app/zombie"] 
