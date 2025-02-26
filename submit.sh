#!/bin/bash

# Checking whether a commit message was provided
if [ -z "$1" ]; then
	echo "Error: No commit message provided."
	echo "Usage: ./submit.sh \"your commit message\""
	exit 1
fi

# Staging updates and pushing to github
# It should be noted that I initially pushed my code with the security token before this so I will not get any errors, however, if you get any errors, then you might need to write the complete the git push command

git add .
git commit -m "$1"
git push
