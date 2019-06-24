#! /bin/bash

local_dir=$(pwd)

case $USER in
    semoog)
	USER=semo
	;;
    *)
	;;
esac

case $OSTYPE in
    darwin*)
	if [[ ! -d "$local_dir/qmk_firmware" ]]; then
            mkdir $local_dir/qmk_firmware
	fi

        if [[ -z "$(ls -A $local_dir/qmk_firmware)" ]]; then
            echo "qmk_firmware directory not found. Cloning to $local_dir/qmk_firmware..."
            git clone --recurse-submodules https://github.com/qmk/qmk_firmware $local_dir/qmk_firmware
        fi
	;;
    *)
        # Assume WSL
	if [[ ! -d "/mnt/c/Users/$USER/qmk_firmware" ]]; then
	    echo "qmk_firmware directory not found. Cloning to C:\\Users\\$USER\\qmk_firmware..."
            git clone --recurse-submodules https://github.com/qmk/qmk_firmware /mnt/c/Users/$USER/qmk_firmware
	fi

	if [[ ! -L "$local_dir/qmk_firmware" ]]; then
    	    rm -rf $local_dir/qmk_firmware	    
	    ln -s /mnt/c/Users/$USER/qmk_firmware $local_dir
    	fi
	;;
esac

echo "Setup complete."
