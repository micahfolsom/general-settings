#!/bin/bash
# Set up a fresh system with my configuration. Can run multiple times and
# there shouldn't be a problem!
set -e

# Install helpful things
printf "Installing basic packages...\n"
sudo apt update
sudo apt install vim git build-essential cmake curl python3-dev \
  python-is-python3 python3-pip openssh-server

# Install Chrome
# TODO

# Install VSCode
# TODO

# Install docker
# https://docs.docker.com/engine/install/ubuntu/
printf "Installing docker...\n"
sudo apt install ca-certificates gnupg lsb-release
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt update
sudo apt-get install docker-ce docker-ce-cli containerd.io \
  docker-compose-plugin

# Copy vim config files
printf "Setting up vim config...\n"
cp -r .vim $HOME
cp .vimrc $HOME
# TODO: open vim so it does plugin setup, then run YouCompleteMe installer?

# Fonts
printf "Copying fonts...\n"
mkdir -p $HOME/.local/share/fonts
cp Inconsolata.ttf $HOME/.local/share/fonts

# Git
mkdir -p $HOME/repos
cp .gitconfig $HOME

# .bashrc, bash_aliases, bash colors
cp .bash_aliases $HOME
grep -qxF -- "# Micah bash colors" $HOME/.bashrc || \
  cat bash_colors >> $HOME/.bashrc
grep -qxF -- "# Python user binaries" $HOME/.bashrc || \
  printf "# Python user binaries\nexport PATH=\${PATH}:$HOME/.local/bin" \
  >> $HOME/.bashrc
