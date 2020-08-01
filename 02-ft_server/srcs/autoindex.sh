# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    autoindex.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 11:33:59 by apuchill          #+#    #+#              #
#    Updated: 2020/07/12 17:42:15 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# This script turns autoindex on or off according to argument $1

INDEX=$1
NGINX_CONF=/etc/nginx/sites-available/nginx.conf

if [[ "$INDEX" == "on" || "$INDEX" == "off" ]];
then
	sed -i -E "/autoindex/ s/on|off/$INDEX/" $NGINX_CONF
	nginx -s reload
	echo "Autoindex option is now set to $INDEX"
else
	echo "Please provide a valid value ('on' or 'off') for autoindex"
fi
