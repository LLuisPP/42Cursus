# **DISK**

### **Creating VM**

Create VM with appropiate settinngs and 30.8GiB disk space

### **Creating partitions**

manual - 500MiB - primary - beginning - /boot - done

max - logical - do not mount - done

### **Configuring encrypted volumes**

/dev/sda5 done finish cancel
``` 
opensesame
``` 

### **Configuring LVM VG**

LVMGroup /dev/mapper/sd5\_crypt

### **Configuring LVM LV**

| LV      | Size   |
|---------|--------|
| root    | 10GiB  |
| swap    | 2.3GiB |
| home    | 5GiB   |
| var     | 3GiB   |
| srv     | 3GiB   |
| tmp     | 3GiB   |
| var-log | 4GiB   |

Finish

### **Configuring FS and mount point**

| LV      | FS   | Mount    |
|---------|:----:|----------|
| home    | ext4 | /home    |
| root    | ext4 | /        | 
| srv     | ext4 | /srv     |
| swap    | swap | area     |
| tmp     | ext4 | /tmp     | 
| var     | ext4 | /var     |
| var-log | ext4 | /var/log |

Finish

### **Configuring GRUB**

/dev/sda

# **PASSWORDS**
``` 
T00rsecret
Ab3lsecret
``` 

# **APPARMOR**

sudo systemctl status apparmor

sudo apt install apparmor-utils

sudo apparmor\_status

sudo systemctl disable apparmor

sudo systemctl enable apparmor

# **SELINUX**

sudo sestatus

getenforce

sudo setenforce disabled

sudo setenforsuce permissive

sudo setenforce enforcing

sudo vim /etc/selinux/config
``` 
SELINUX=disabled
SELINUX=enforcing
SELINUX=permissive
``` 

# **HOSTNAME**

hostname

cat /etc/hostname

cat /etc/hosts 

sudo hostname NEW\_NAME

sudo nano /etc/hostname

sudo nano /etc/hosts

### **Debian**
```
systemctl enable --now dbus.service dbus.socket \&\& systemctl status dbus.service dbus.socket
```

### **Common**

hostnamectl

sudo hostnamectl set-hostname NEW\_NAME


# **NETWORKING**

This steps are only needed if we want static ip addresses

### **Rocky**

systemctl status NetworkManager

NetworkManager --print-config

nmcli device show enp1s0

cat /etc/NetworkManager/system-connections/enp1s0.nmconnection

nmtui

### **Debian**

sudo cp /etc/network/interfaces /root/

sudo vim /etc/network/interfaces 

Look for the primary network interface enp0s5:
```
allow-hotplug enp0s5
iface enp0s5 inet dhcp
```
Remove dhcp and allow-hotplug lines. Append the following configuration to set up/add new static IP on Debian Linux 10/11. Here is my sample config file:
```
# The loopback network interface
auto lo
iface lo inet loopback
 
# The primary network interface
auto enp0s5
iface enp0s5  inet static
 address 192.168.2.236
 netmask 255.255.255.0
 gateway 192.168.2.254
 dns-domain sweet.home
 dns-nameservers 192.168.2.254 1.1.1.1 8.8.8.8
```

sudo systemctl restart networking.service \&\& systemctl status networking.service

# **SSH**

### **Rocky**

sudo cp /usr/lib/firewalld/services/ssh.xml /etc/firewalld/services/ssh.xml

sudo vim /etc/firewalld/services/ssh.xml
```
	<port protocol="tcp" port="4242"/>
```

sudo dnf install openssh-server policycoreutils-python-utils -y

sudo semanage port -a -t ssh\_port\_t -p tcp 4242

### **Debian**

sudo apt install openssh-server -y

### **Common**

cp /etc/ssh/sshd\_config /etc/ssh/sshd\_config.bak
``` 
Port 4242
AddressFamily inet
SyslogFacility AUTH
LogLevel VERBOSE
LoginGraceTime 2m
PermitRootLogin no
MaxAuthTries 3
MaxSessions 5
PublicKeyAuthentication yes
HostbasedAuthentication no
IgnoreRhosts yes
#PasswordAuthentication no
PermitEmptyPasswords no
AllowTcpForwarding no
X11Forwarding no
ClientAliveInterval 60
ClientAliveCountMax 3
Banner /etc/ssh/iks.txt
AllowUsers: username sshuser\@ip:port
AllowGroups: groupname
Ciphers aes128-ctr,aes192-ctr,aes256-ctr
KexAlgorithms ecdh-sha2-nistp256,ecdh-sha2-nistp384,ecdh-sha2-nistp521,diffie-hellman-group14-sha1,diffie-hellman-group-exchange-sha256
MACs hmac-sha2-256,hmac-sha2-512
``` 

sudo systemctl restart sshd \&\& systemctl status sshd

ssh-copy-id -p 4242 username\@remote-host

sudo sshd -t

sudo sshd -T


# **USER & SUDO**

\#groupadd user42

\#usermod -aG user42 username

\#apt install sudo \|\| \#dnf install sudo

mkdir /var/log/sudo

export EDITOR=vim && sudo visudo
``` 
Defaults requiretty
Defaults badpass_message="Wrong password P'takh, stop dishonoring your family."
Defaults passwd_tries=3
Defaults logfile="/var/log/sudo/sudo.log"
Defaults log_input,log_output
Defaults iolog_dir="/var/log/sudo"
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

#username	ALL=(ALL) NOPASSWD: ALL
``` 

sudo useradd -D

sudo vim /etc/default/useradd
```
SHELL=/bin/bash
```

sudo useradd -m -G user42 username && sudo passwd username

# **PASSWORD**

sudo cp /etc/login.defs /etc/login.defs.bak

sudo vim /etc/login.defs 
```
PASS_MAX_DAYS	30
PASS_MIN_DAYS	2
PASS_WARN_AGE	7
```

### **Debian**

sudo apt install libpam-pwquality -y

sudo cp /etc/pam.d/common-password /etc/pam.d/common-password.bak

sudo vim /etc/pam.d/common-password 
```
password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

### **Rocky**

sudo cp /etc/pam.d/system-auth /etc/pam.d/system-auth.bak

sudo vim /etc/pam.d/system-auth
```
password    sufficient    pam_unix.so try_first_pass use_authtok nullok sha512 shadow remember=5
```

sudo cp /etc/security/pwquality.conf /etc/security/pwquality.conf.bak

sudo vim /etc/security/pwquality.conf 
```
ddifok=7 minlen=10 dcredit=-1 ucredit=-1 lcredit=-1 minclass=3 maxrepeat=3 usercheck=1 enforcing=1 enforce_for_root
```

### **Common**
sudo chage -M \<days\> \<username\>

sudo chage -m \<days\> \<username\>

sudo chage -W \<days\> \<username\>

sudo chage -l \<username\>

sudo chage -E \$(date +%d/%m/%Y) -m 2 -M 30 -I 10 -W 7 \<username\>

# **UFW**

sudo apt install ufw -y

sudo ufw default deny incoming

sudo ufw default allow outgoing

sudo ufw allow 4242

sudo ufw enable

sudo ufw status verbose

sudo ufw status numbered

# **FIREWALLD**

sudo vim /etc/chrony.conf
```
#Disable chrony from listening port UDP 323
cmdport 0
```

sudo dnf install firewalld -y

sudo systemctl enable --now firewalld

sudo firewall-cmd --state

sudo firewall-cmd --get-active-zones

sudo firewall-cmd --list-all

During SSH install we already changed service port for SSH to be 4242 performing this:
```
sudo cp /usr/lib/firewalld/services/ssh.xml /etc/firewalld/services/ssh.xml
sudo vim /etc/firewalld/services/ssh.xml
  <port protocol="tcp" port="4242"/>
sudo dnf install openssh-server policycoreutils-python-utils -y
sudo semanage port -a -t ssh\_port\_t -p tcp 4242
```

sudo firewall-cmd --zone=public --permanent --add-service=ssh

sudo firewall-cmd --zone=public --permanent --remove-service=cockpit

sudo firewall-cmd --reload

# **BASH**

sudo apt install sysstat -y     \|\|     sudo dnf install sysstat -y

sudo systemctl enable --now sysstat \&\& systemctl status sysstat

monitoring.sh -> wall -> Startup and every 10 minutes

systemd-analyze calendar \--iterations=5 \"\*-\*-\* \*:00/10:00\"

sudo systemctl enable monitoring.timer

sudo systemctl list-unit-files --type=timer --state=enabled

# **LIGHTTPD**

sudo apt install lighttpd -y \|\| sudo dnf -y install epel-release && sudo dnf -y update && sudo dnf -y install lighttpd

sudo lighty-enable-mod fastcgi \&\& sudo lighty-enable-mod fastcgi-php \|\| sudo dnf -y install php-fpm lighttpd-fastcgi

sudo ufw allow http \|\| sudo firewall-cmd --permanent --zone=public --add-service=http \&\& sudo firewall-cmd --reload

sudo systemctl enable --now lighttpd \&\& systemctl status lighttpd

### **Rocky**

sudo setsebool -P httpd_setrlimit on

sudo vim /etc/lighttpd/lighttpd.conf
```
#server.use-ipv6 = "enable"
#server.bind = "localhost"
server.bind = host_ip_address	default
```

sudo vim /etc/lighttpd/conf.d/dirlisting.conf
```
#dir-listing.exclude = ( "~$" )
#dir-listing.encoding = "UTF-8"
```

sudo vim /etc/systemd/system/multi-user.target.wants/lighttpd.service
```
After=network-online.target
```

sudo systemctl restart lighttpd \&\& systemctl status lighttpd

# **MARIADB**

sudo apt install mariadb-server -y \|\| sudo dnf -y install mariadb mariadb-server

sudo systemctl enable --now mariadb.service \&\& systemctl status mariadb.service

sudo mysql\_secure\_installation
``` 
t00Rmaria
``` 
sudo mariadb -p
``` 
CREATE DATABASE wp_database;
CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wpS3cret';
GRANT ALL PRIVILEGES ON wp_database.* TO wordpress@localhost;
FLUSH PRIVILEGES;
``` 

mariadb -uwordpress -pwpS3cret wp_database

# **PHP**

sudo apt install php-cgi php-mysql php-fpm -y \|\| sudo dnf -y install php php-mysqlnd php-pdo php-gd php-mbstring

sudo vim /etc/php/8.2/cgi/php.ini \|\| sudo vim /etc/php.ini
``` 
cgi.fix_pathinfo=1
``` 

### **Debian**

sudo vim /etc/php/8.2/fpm/pool.d/www.conf
``` 
;listen = /run/php/php8.2-fpm.sock
listen = 127.0.0.1:9000
``` 

sudo vim /etc/lighttpd/conf-available/15-fastcgi-php.conf
```
#"bin-path" => "/usr/bin/php-cgi",
#"socket" => "/run/lighttpd/php.socket",
"host" => "127.0.0.1",
"port" => "9000",
```

sudo systemctl enable --now php8.2-fpm && systemctl status php8.2-fpm

### **Rocky**

sudo vim /etc/php-fpm.d/www.conf 
``` 
user = lighttpd
group = lighttpd
;listen = /run/php-fpm/www.sock
listen = 127.0.0.1:9000
``` 

sudo vim /etc/lighttpd/modules.conf
``` 
include "conf.d/fastcgi.conf"
``` 

sudo vim /etc/lighttpd/conf.d/fastcgi.conf
``` 
fastcgi.server += ( ".php" =>
		((
			"host" => "127.0.0.1",
			"port" => "9000",
			"bin-path" => "/usr/bin/php-cgi"
		))
)
``` 

sudo systemctl enable --now php-fpm.service \&\& systemctl status php-fpm.service

### **Common**

sudo vim /var/www/html/phpinfo.php \|\| sudo vim /var/www/lighttpd/phpinfo.php
``` 
<?php
phpinfo();
?>
``` 
sudo systemctl restart lighttpd \&\& systemctl status lighttpd

### **TROUBLESHOOTING SELINUX**

getsebool -a | grep httpd

semanage boolean --list | grep httpd

sudo dnf install setroubleshoot-server -y

sealert -a /var/log/audit/audit.log > sealert.txt

ausearch -c 'lighttpd' --raw | audit2allow -M my-lighttpd

semodule -i my-lighttpd.pp

semodule -X 500 -i my-lighttpd.pp


# **WORDPRESS**

sudo apt install wget zip -y \|\| sudo dnf install wget zip -y

cd /var/www \&\& sudo wget [https://wordpress.org/latest.zip](https://wordpress.org/latest.zip)

sudo unzip latest.zip 

sudo mv html/ html\_old/ \&\& sudo mv wordpress/ html \|\| sudo mv lighttpd/ lighttp\_old/ \&\& sudo mv wordpress/ lighttpd

sudo chmod -R 755 html

sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php || sudo cp /var/www/lighttpd/wp-config-sample.php /var/www/lighttpd/wp-config.php

sudo vim /var/www/html/wp-config.php \|\| sudo vim /var/www/lighttpd/wp-config.php
```
define( 'DB_NAME', 'wp_database' );
define( 'DB_USER', 'wordpress' );
define( 'DB_PASSWORD', 'wpS3cret' );
```

# **PROMETHEUS**

sudo groupadd \--system prometheus

sudo useradd -M -r -s /sbin/nologin \--system -g prometheus prometheus

sudo mkdir /var/lib/prometheus

for i in rules rules.d files\_sd; do sudo mkdir -p
/etc/prometheus/\${i}; done

sudo apt -y install wget curl vim \|\| sudo dnf -y install wget curl vim tar

cd /usr/src

curl -s
https://api.github.com/repos/prometheus/prometheus/releases/latest \|
grep browser\_download\_url \| grep linux-amd64 \| cut -d \'\"\' -f 4 \| 
xargs sudo wget

sudo tar xvf prometheus\*.tar.gz 

export PROM_SRC=/usr/src/prometheus-*

sudo cp $PROM_SRC/prometheus.yml /etc/prometheus/

sudo cp $PROM_SRC/prometheus /usr/local/bin/ \&\& sudo cp $PROM_SRC/promtool /usr/local/bin/

sudo cp -r $PROM_SRC/consoles /etc/prometheus \&\& sudo cp -r $PROM_SRC/console_libraries /etc/prometheus

prometheus --version

sudo vim /etc/prometheus/prometheus.yml
```
scrape_configs:
  #The job name is added as a label `job=<job_name>` to any timeseries scraped from this config.
  - job_name: "prometheus"

    #metrics_path defaults to '/metrics'
    #scheme defaults to 'http'.

    static_configs:
      - targets: ["localhost:9090"]
```

sudo chown prometheus:prometheus /etc/prometheus \&\& sudo chown prometheus:prometheus /var/lib/prometheus

sudo vim /etc/systemd/system/prometheus.service
```
[Unit]
Description=Prometheus
Wants=network-online.target
After=network-online.target

[Service]
User=prometheus
Group=prometheus
Type=simple
ExecStart=/usr/local/bin/prometheus \
    --config.file /etc/prometheus/prometheus.yml \
    --storage.tsdb.path /var/lib/prometheus/ \
    --web.console.templates=/etc/prometheus/consoles \
    --web.console.libraries=/etc/prometheus/console_libraries

[Install]
WantedBy=multi-user.target
```

sudo systemctl daemon-reload

sudo systemctl enable --now prometheus && systemctl status prometheus

sudo ufw allow 9090/tcp \|\| sudo firewall-cmd --permanent --zone=public --add-port=9090/tcp

# **NODE\_EXPORTER**

sudo useradd -M -r -s /bin/false node\_exporter

cd /usr/src

curl -s
https://api.github.com/repos/prometheus/node\_exporter/releases/latest \|
grep browser\_download\_url \| grep linux-amd64 \| cut -d \'\"\' -f 4 \|
xargs sudo wget 

sudo tar -xvf node\_exporter\*.tar.gz

cd node\_exporter\*/

sudo cp node\_exporter /usr/local/bin

node\_exporter \--version

sudo vim /etc/systemd/system/node\_exporter.service
```
[Unit]
Description=Node Exporter
After=network.target

[Service]
User=node_exporter
Group=node_exporter
Type=simple
ExecStart=/usr/local/bin/node_exporter

[Install]
WantedBy=multi-user.target
```

sudo systemctl daemon-reload

sudo systemctl enable --now node\_exporter \&\& systemctl status node\_exporter

sudo ufw allow 9100 \|\| sudo firewall-cmd --permanent --zone=public --add-port=9100/tcp

sudo vim /etc/prometheus/prometheus.yml

```
- job_name: "node"
    scrape_interval: 5s
    static_configs:
      - targets: ['localhost:9100']
```

sudo systemctl restart prometheus \&\& systemctl status prometheus

# **BLACKBOX EXPORTER**

sudo useradd -M -r -s /bin/false blackbox

cd /usr/src

curl -s https://api.github.com/repos/prometheus/blackbox\_exporter/releases/latest \| grep browser\_download\_url \| grep linux-amd64 \| cut -d \'\"\' -f 4 \| xargs sudo wget

sudo tar xvzf blackbox\_exporter-\*.linux-amd64.tar.gz

cd blackbox\_exporter-\*.linux-amd64

sudo cp blackbox\_exporter /usr/local/bin && sudo mkdir /etc/blackbox \&\& sudo cp blackbox.yml /etc/blackbox

blackbox\_exporter --version

sudo chown blackbox:blackbox /usr/local/bin/blackbox\_exporter

sudo vim /etc/systemd/system/blackbox.service
```
[Unit]
Description=Blackbox Exporter Service
Wants=network-online.target
After=network-online.target

[Service]
Type=simple
User=blackbox
Group=blackbox
ExecStart=/usr/local/bin/blackbox_exporter \
  --config.file=/etc/blackbox/blackbox.yml \
  --web.listen-address=":9115"

Restart=always

[Install]
WantedBy=multi-user.target

```

sudo systemctl daemon-reload

sudo systemctl enable --now blackbox \&\& sudo systemctl status blackbox

sudo ufw allow 9115 \|\| sudo firewall-cmd --permanent --zone=public --add-port=9115/tcp

sudo vim /etc/prometheus/prometheus.yml
```
  # Using the [http_2xx] module
  - job_name: 'HTTP_Wordpressp'
    metrics_path: /probe
    params:
      module: [http_2xx]
    static_configs:
      - targets:
        # The http host you are targeting
        - http://192.168.122.160
    relabel_configs:
      - source_labels: [__address__]
        target_label: __param_target
      - source_labels: [__param_target]
        target_label: instance
      - target_label: __address__
        #Where Blackbox exporter was installed plust port
        replacement: localhost:9115

  # Using the [icmp] module
  - job_name: 'ICMP_Probe'
    metrics_path: /probe
    params:
      module: [icmp]
    static_configs:
      - targets:
        # The hostname or IP address of the host you are targeting
        - 192.168.122.160
    relabel_configs:
      - source_labels: [__address__]
        target_label: __param_target
      - source_labels: [__param_target]
        target_label: instance
      - target_label: __address__
        # Where Blackbox exporter was installed plust port
        replacement: localhost:9115

  # Using the [ssh_banner] module
  - job_name: 'SSH_Probe'
    metrics_path: /probe
    params:
      module: [ssh_banner]
    static_configs:
      - targets:
        # The host you are targeting plus ssh port
        - 192.168.122.160:4242
    relabel_configs:
      - source_labels: [__address__]
        target_label: __param_target
      - source_labels: [__param_target]
        target_label: instance
      - target_label: __address__
        # Where Blackbox exporter was installed plust port
        replacement: localhost:9115
```

sudo systemctl restart prometheus \&\& systemctl status prometheus

# **GRAFANA**

### **Rocky**

sudo vim /etc/yum.repos.d/grafana.repo
```
[grafana]
name=grafana
baseurl=https://packages.grafana.com/oss/rpm
repo_gpgcheck=1
enabled=1
gpgcheck=1
gpgkey=https://packages.grafana.com/gpg.key
sslverify=1
sslcacert=/etc/pki/tls/certs/ca-bundle.crt
```

sudo dnf repolist

sudo dnf install grafana -y

### **Debian**

sudo apt install -y gnupg2 curl software-properties-common

curl -fsSL https://packages.grafana.com/gpg.key \| sudo gpg \--dearmor
-o /etc/apt/trusted.gpg.d/grafana.gpg

sudo add-apt-repository \"deb https://packages.grafana.com/oss/deb
stable main\"

sudo apt update && sudo apt -y install grafana

### **Common**

sudo systemctl enable --now grafana-server \&\& systemctl status grafana-server

sudo ufw allow proto tcp from any to any port 3000 \|\| sudo firewall-cmd --permanent --zone=public --add-port=3000/tcp

admin/admin → grafS3cret

Datasource → Prometheus

Dashboard → 7587

# **FAIL2BAN**

sudo apt install rsyslog fail2ban -y \|\| sudo dnf install epel-release \&\& sudo dnf install fail2ban -y

sudo systemctl enable --now fail2ban \&\& systemctl status fail2ban

journalctl -u sshd.service

journalctl -u fail2ban.service

sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local

### **Debian**

udo vim /etc/fail2ban/jail.d/sshd.conf

```
[sshd]
enabled   = true
port      = 4242
maxretry  = 3
findtime  = 10m
bantime   = 1h
ignoreip  = 127.0.0.1/8 192.168.39.128
logpath   = %(sshd_log)s
backend   = %(sshd_backend)s
banaction = ufw
```

### **Rocky**
sudo vim /etc/fail2ban/jail.d/sshd.conf
```
[sshd]
enabled   = true
port      = 4242
maxretry  = 3
findtime  = 10m
bantime   = 1h
ignoreip  = 127.0.0.1/8 192.168.39.131
logpath   = %(sshd_log)s
backend   = %(sshd_backend)s
banaction = iptables-allports
```

sudo systemctl restart fail2ban \&\& systemctl status fail2ban

### **Under Construction**

sudo vim /etc/fail2ban/jail.d/httpd.conf
```
[lighttpd-auth]
enabled = true
port = http
filter = lighttpd-auth
logpath = /var/log/lighttpd*/*error*.log
bantime = 600 # 10 minutes
maxretry = 6
action = iptables-multiport[name=NoAuthFailures, port="http,https"]

[lighttpd-login]
enabled = true
filter = lighttpd-login
action = iptables-multiport[name=NoLoginFailures, port="http,https"]
logpath = /var/log/lighttpd*/*access*.log
bantime = 600 # 10 minutes
maxretry = 6

[lighttpd-badbots]
enabled  = true
filter = lighttpd-badbots
action = iptables-multiport[name=BadBots, port="http,https"]
logpath = /var/log/lighttpd*/*access*.log
bantime = 86400 # 1 day
maxretry = 1

[lighttpd-noscript]
enabled = true
action = iptables-multiport[name=NoScript, port="http,https"]
filter = lighttpd-noscript
logpath = /var/log/lighttpd*/*access*.log
maxretry = 6
bantime  = 86400 # 1 day

[lighttpd-proxy]
enabled = true
action = iptables-multiport[name=NoProxy, port="http,https"]
filter = lighttpd-proxy
logpath = /var/log/lighttpd*/*access*.log
maxretry = 0
bantime  = 86400 # 1 day

[lighttpd-wp-login]
enabled = true
port = http,https
filter = lighttpd-wp-login
logpath = /var/log/lighttpd*/*access*.log
maxretry = 3
findtime = 120
bantime = 1200 # 20 minutes
```

sudo vim /etc/fail2ban/filter.d/lighttpd-proxy.conf
```
[Definition]
failregex = ^<host> -.*GET http.*
ignoreregex =
```

sudo vim /etc/fail2ban/filter.d/lighttpd-noscript.conf
```
[Definition]
failregex = ^<host> -.*GET.*(\.php|\.asp|\.exe|\.pl|\.cgi|\scgi)
ignoreregex =
```

sudo vim /etc/fail2ban/filter.d/lighttpd-auth.conf
```
[Definition]
failregex = no user/password was provided for basic authentication.*client: <host>
            user .* was not found in.*client: <host>
            user .* password mismatch.*client: <host>
ignoreregex =
```

sudo vim /etc/fail2ban/filter.d/lighttpd-login.conf
```
[Definition]
failregex = ^<host> -.*POST /sessions HTTP/1\.." 200
ignoreregex =
```

sudo vim /etc/fail2ban/filter.d/lighttpd-wp-login.conf
```
[Definition]
failregex = <host>.*] "POST /wp-login.php
ignoreregex =
```

sudo fail2ban-client status sshd 

sudo fail2ban-client status lighttpd

iptables -L -n

sudo fail2ban-client set YOURJAILNAMEHERE unbanip IPADDRESSHERE \|\| sudo fail2ban-client unban --all

# **TESTING**

startx

echo \"\$XDG\_SESSION\_TYPE\"

lsblk

cat /etc/passwd

cat /etc/group

id -Gn

sudo -V

apparmor\_status

sestatus

cat /etc/hostname

cat /etc/hosts

hostnamectl

sudo less /etc/sudoers

sudo useradd -m -s /usr/bin/bash -G user42 username && sudo passwd username

less etc/login.defs           

sudo chage -l username

less /etc/pam.d/common-password \|\| less /etc/pam.d/system-auth

less /etc/security/pwquality.conf

sudo sudoreplay -l -d /var/log/sudo

sudo sudoreplay -d /var/log/sudo 000001

```
rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update
```

brew install nmap

nmap -Pn host

nmap -sU -v host

sudo ufw status verbose

sudo ufw status numbered

sudo firewall-cmd --state

sudo firewall-cmd --get-active-zones

sudo firewall-cmd --list-all

sudo nft list ruleset

ss -tunl

nc -vnzt Host_IP TCP_Port

nc -vnzu Hodt_IP UFP_Port

ssh user\@host -p4242

ssh root\@host -p4242

sudo apt install stress s-tui -y | sudo dnf install stress -y

stress \--cpu \$(nproc) \--timeout 720 \& \&\& s-tui 

lighttpd -tt -f /etc/lighttpd/lighttpd.conf

lighttpd -p -f /etc/lighttpd/lighttpd.conf

sudo apt install luajit liblua5.1-0-dev libssl-dev git build-essential -y \|\| sudo dnf -y groupinstall 'Development Tools' \&\& sudo dnf -y install openssl-devel git perl-FindBin

cd /usr/src \&\& sudo git clone https://github.com/wg/wrk.git \&\& cd wrk

luajit -v \&\& sudo make WITH\_LUAJIT=/usr WITH\_OPENSSL=/usr \|\| sudo make 

sudo cp wrk /usr/local/bin/

wrk -t2 -c400 -d120s http://localhost/index.php
