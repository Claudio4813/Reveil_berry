#!/bin/bash
pstree | grep  xterm
echo "appuyer"
read touche
case $touche in
