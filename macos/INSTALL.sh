#!/bin/bash

xcode-select --install

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /Users/$USER/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
brew update

brew tap osx-cross/avr
brew install avr-gcc
brew install avrdude