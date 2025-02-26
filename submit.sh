#!/bin/bash

# Checking whether a commit message was provided
if [ -z "$1" ]; then
	echo "Error: No commit message provided."
	echo "Usage: ./submit.sh \"your commit message\""
	exit 1
fi

# Staging updates and pushing to github
git add .
git commit -m "$1"
git push
