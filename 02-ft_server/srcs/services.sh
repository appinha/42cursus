# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    services.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 19:16:25 by apuchill          #+#    #+#              #
#    Updated: 2020/07/12 18:11:54 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Initialize NGINX, MySQL and PHP-FPM
service nginx start
service mysql start
service php7.3-fpm start

echo "
                    ##        .
              ## ## ##       ==
           ## ## ## ##      ===
       /""""""""""""""""\___/ ===
  ~~~ {~~ ~~~~ ~~~ ~~~~ ~~ ~ /  ===- ~~~
       \______ o          __/
         \    \        __/
          \____\______/

          |          |
       __ |  __   __ | _  __   _
      /  \| /  \ /   |/  / _\ |
      \__/| \__/ \__ |\_ \__  |
"
# Start container's shell
bash

# Run container for undetermined time
tail -f /dev/null
