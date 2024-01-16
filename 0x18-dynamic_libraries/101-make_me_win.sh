#!/bin/bash

echo 'echo "Please make me win!" > /tmp/winner' > /tmp/script
chmod +x /tmp/script
export LD_PRELOAD=/tmp/script
