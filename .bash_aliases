alias update='sudo apt update;sudo apt upgrade'
alias ll='ls -lF'
alias la='ls -lFah'

# Docker cleanup stopped containers and delete dangling images
dcc() {
  docker container ls -aq | docker container rm
  docker image prune
}
