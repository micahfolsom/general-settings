alias update='sudo apt update;sudo apt upgrade -y'
alias ls='ls -lFah --color=auto'

# Docker cleanup stopped containers and delete dangling images
docker-clean() {
  docker container ls -aq | docker container rm
  yes | docker image prune
  yes | docker builder prune
}
# docker go nuclear - kill ALL containers, remove ALL containers, delete ALL
# images
docker-purge() {
  docker kill "$(docker ps -q)";
  docker rm "$(docker ps -q)";
  yes | docker image prune -a;
  yes | docker builder prune
}
# Numpy, calm down - limit the number of threads
numpy-chill() {
  export OMP_NUM_THREADS="$1"
  export OPENBLAS_NUM_THREADS="$1"
  export MKL_NUM_THREADS="$1"
  export VECLIB_MAXIMUM_THREADS="$1"
  export NUMEXPR_NUM_THREADS="$1"
}
