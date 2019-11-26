#!/bin/bash
git add $1
git commit -m "$1 + renewal"
git push -u origin master
