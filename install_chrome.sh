#!/bin/bash
# Install Chrome
set -e
printf "Installing Google Chrome...\n"
cd $HOME/Downloads
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb
rm -f google-chrome-stable_current_amd64.deb
cd $HOME/repos/general-settings
