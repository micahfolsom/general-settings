alias update='sudo apt update;sudo apt upgrade -y'
alias ls='ls -lFah'

# Docker cleanup stopped containers and delete dangling images
docker-clean() {
  docker container ls -aq | docker container rm
  docker image prune
  docker builder prune
}
