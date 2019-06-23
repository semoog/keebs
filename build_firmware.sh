#! /bin/bash

board=$1
keymap=$2

local_dir=~/personal/keyboards
board_dir=$board

# Prettyness
green='\033[0;32m'
red='\033[0;31m'
reset='\033[0m'

# Map to specific personal boards so I don't have to specify board maker
case "$board" in
    space65)
        board_dir=gray_studio/$board
        ;;
    *)
        ;;
esac

tmp_dir=$local_dir/qmk_firmware/keyboards/$board_dir/keymaps

if [ ! -d $board ] || [ ! -d $tmp_dir ]; then
    echo -e "${red}Board not found. Exiting...${reset}"
    exit 1
fi

tmp_dir=$tmp_dir/$keymap

cleanup () {
    echo "Cleaning up..."
    rm -rf $tmp_dir
}

trap "cleanup" 0

# Create symlink while we build
echo "Creating symlink to $tmp_dir"
ln -s $local_dir/$board/$keymap $tmp_dir

# Build
cd $local_dir/qmk_firmware
make $board_dir:$keymap

# Format build file location
board_dir=${board_dir//\//_}
build=$local_dir/qmk_firmware/"$board_dir"_$keymap.hex

# Move the build out into our personal directory
if [ -f $build ]; then
    if [ ! -d $local_dir/$board/builds ]; then
        mkdir $local_dir/$board/builds
    fi
    echo "Copying build $build to $local_dir/$board/builds"
    mv -f $build $local_dir/$board/builds
else
    echo -e "${red}Build not found... Check the folder manually, maybe the name got changed.${reset}"
fi

echo -e "${green}Build finished.${reset}"