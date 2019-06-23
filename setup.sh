#! /bin/bash

local_dir=$HOME/personal/keebs

case $USER in
    semoog)
	USER=semo
	;;
    *)
	;;
esac

case $OSTYPE in
    darwin*)
	if [[ "$(ls -A $HOME/personal/keebs/qmk_firmware)" ]]; then
	    git submodule update --init
	fi
	;;
    *)
	if [[ ! -d "/mnt/c/Users/$USER/qmk_firmware" ]]; then
	    echo "QMK firmware directory not found. Please clone to C:\\Users\\$USER\\qmk_firmware"
	elif [[ ! -L "$local_dir/qmk_firmware" ]]; then
    	    rm -rf $local_dir/qmk_firmware	    
	    ln -s /mnt/c/Users/$USER/qmk_firmware $local_dir
    	fi
	;;
esac
