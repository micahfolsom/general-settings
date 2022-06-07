alias update='sudo apt update;sudo apt upgrade -y'
alias ls='ls -lFah --color=auto'

# Docker cleanup stopped containers and delete dangling images
docker-clean() {
  docker container ls -aq | docker container rm
  yes | docker image prune
  yes | docker builder prune
}
