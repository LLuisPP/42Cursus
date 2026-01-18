#!/bin/sh

DOMAIN="lprieto-.42.fr"

echo "\033[1;97m-----------------------------------------------------------------------------"
echo "--------------------------------lprieto- tests-------------------------------"
echo "----------------------------------------------------------------------------- \e[0m"

echo

echo "TEST 1 - CONTAINERS: docker ps --format {{.Names}}{{.Status}}"
echo "NAME      \tSTATUS \033[1;92m"
docker ps --format "{{.Names}}\t\t{{.Status}}"
echo "\e[0m"
echo "----------------------------------------------------------------------------- \e[0m"


echo "TEST 2 - NGINX LISTEN 443: ss -tuln | grep ':443' >/dev/null 2>&1"
ss -tuln | grep ':443' >/dev/null 2>&1
if [ $? -eq 0 ]; then
	echo "\033[1;92mOK: port 443 is listening \e[0m"
else
	echo "\033[1;91mERROR: port 443 is NOT listening \e[0m"
fi
echo
echo "----------------------------------------------------------------------------- \e[0m"


echo "TEST 3 - HTTPS response with curl: curl -k -I https://$DOMAIN 2>/dev/null | head -n 1"
echo "\033[1;92m"
curl -k -I https://$DOMAIN 2>/dev/null | head -n 1
echo "\e[0m"
echo "----------------------------------------------------------------------------- \e[0m"

echo "TEST 4 - TLS version with OpenSSL: openssl s_client -connect $DOMAIN:443 </dev/null 2>/dev/null | grep Protocol"
echo "\033[1;92m"
openssl s_client -connect $DOMAIN:443 </dev/null 2>/dev/null | grep -E "Protocol"
echo "\e[0m"
echo "----------------------------------------------------------------------------- \e[0m"


echo "TEST 5 - WORDPRESS INSTALATION: docker exec -it wordpress wp core is-installed --allow-root >/dev/null 2>&1"
docker exec -it wordpress wp core is-installed --allow-root >/dev/null 2>&1
if [ $? -eq 0 ]; then
	echo "\033[1;92mOK: WordPress is installed \e[0m"
else
	echo "\033[1;91mERROR: Wordpress is NOT installed \e[0m"
fi
echo
echo "----------------------------------------------------------------------------- \e[0m"

echo "TEST 6 - CHECKING WORDPRESS DDBB connection: docker exec -it wordpress wp db check --allow-root >/dev/null 2>&1"
docker exec -it wordpress wp db check --allow-root >/dev/null 2>&1
if [ $? -eq 0 ]; then
	echo "\033[1;92mOK: mariadb is accesible \e[0m"
else
	echo "\033[1;91mERROR: mariadb is NOT accesible \e[0m"
fi
echo

echo "\033[1;97m This prooves all mandatory parts at once, but try one by one with instructions in DEV_DOC.md and README.md \e[0m \n"

