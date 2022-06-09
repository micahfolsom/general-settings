#!/bin/bash
# Set up a fresh system with my configuration. Can run multiple times and
# there shouldn't be a problem!
set -e

# Install helpful things
printf "Installing basic packages...\n"
sudo apt update
sudo apt install -y vim git build-essential cmake curl python3-dev \
  python-is-python3 python3-pip openssh-server wget gpg

# Install chrome
./install_chrome.sh

# Install VSCode
./install_vscode.sh

# Install docker
./install_docker.sh

# Copy vim config files
printf "Setting up vim config...\n"
cd $HOME/repos/general-settings
cp -r .vim $HOME
cp .vimrc $HOME

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
