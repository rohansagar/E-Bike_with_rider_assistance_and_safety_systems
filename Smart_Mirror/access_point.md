This file is a version of the file available [ Here ]( https://github.com/SurferTim/documentation/blob/6bc583965254fa292a470990c40b145f553f6b34/configuration/wireless/access-point.md )

## Setting up a Raspberry Pi as an access point in a standalone network

The Raspberry Pi can be used as a wireless access point, running a standalone network. This can be done using the inbuilt wireless features of the Raspberry Pi 3 or Raspberry Pi Zero W, or by using a suitable USB wireless dongle that supports access points. In this project we are using a Raspberry Pi 3 model B+ as it is capable of creating a 5Ghz Access point.

Note that this documentation was tested on a Raspberry Pi 3, and it is possible that some USB dongles may need slight changes to their settings. If you are having trouble with a USB wireless dongle, please check the forums.

In order to work as an access point, the Raspberry Pi will need to have access point software installed, along with DHCP server software to provide connecting devices with a network address. Ensure that your Raspberry Pi is using an up-to-date version of Raspbian (dated 2017 or later).

Use the following to update your Raspbian installation:
```
sudo apt-get update
sudo apt-get upgrade
```
Install all the required software in one go with this command: 
```
sudo apt-get install dnsmasq hostapd
```
Since the configuration files are not ready yet, turn the new software off as follows: 
```
sudo systemctl stop dnsmasq
sudo systemctl stop hostapd
```

### Configuring a static IP

We are configuring a standalone network to act as a server, so the Raspberry Pi needs to have a static IP address assigned to the wireless port. This documentation assumes that we are using the standard 192.168.x.x IP addresses for our wireless network, so we will assign the server the IP address 192.168.0.1. It is also assumed that the wireless device being used is `wlan0`.

To configure the static IP address, edit the dhcpcd configuration file with: 
```
sudo nano /etc/dhcpcd.conf
```
Go to the end of the file and edit it so that it looks like the following:
```
interface wlan0
    static ip_address=192.168.4.1/24

Now restart the dhcpcd daemon and set up the new `wlan0` configuration:

```
sudo service dhcpcd restart
``

### Configuring the DHCP server (dnsmasq)

The DHCP service is provided by dnsmasq. By default, the configuration file contains a lot of information that is not needed, and it is easier to start from scratch. Rename this configuration file, and edit a new one:

```
sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.orig  
sudo nano /etc/dnsmasq.conf
```

Type or copy the following information into the dnsmasq configuration file and save it:

```
interface=wlan0      # Use the require wireless interface - usually wlan0
  dhcp-range=192.168.4.2,192.168.4.20,255.255.255.0,24h
```

So for `wlan0`, we are going to provide IP addresses between 192.168.4.2 and 192.168.4.20, with a lease time of 24 hours. If you are providing DHCP services for other network devices (e.g. eth0), you could add more sections with the appropriate interface header, with the range of addresses you intend to provide to that interface.

There are many more options for dnsmasq; see the [dnsmasq documentation](http://www.thekelleys.org.uk/dnsmasq/doc.html) for more details.

### Configuring the access point host software (hostapd)

You need to edit the hostapd configuration file, located at /etc/hostapd/hostapd.conf, to add the various parameters for your wireless network. After initial install, this will be a new/empty file.

```
sudo nano /etc/hostapd/hostapd.conf
```

Add the information below to the configuration file. This configuration assumes we are using channel 7, with a network name of NameOfNetwork, and a password AardvarkBadgerHedgehog. Note that the name and password should **not** have quotes around them. 

```
ssid=Name_of_the_network
wpa_passphrase=password_for_the_network

country_code=US

interface=wlan0
driver=nl80211

wpa=2
wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP

macaddr_acl=0

logger_syslog=0
logger_syslog_level=4
logger_stdout=-1
logger_stdout_level=0

hw_mode=a
wmm_enabled=1

# N
ieee80211n=1
require_ht=1
ht_capab=[MAX-AMSDU-3839][HT40+][SHORT-GI-20][SHORT-GI-40][DSSS_CCK-40]

# AC
ieee80211ac=1
require_vht=1
ieee80211d=0
ieee80211h=0
vht_capab=[MAX-AMSDU-3839][SHORT-GI-80]
vht_oper_chwidth=1
channel=36
vht_oper_centr_freq_seg0_idx=42
```

We now need to tell the system where to find this configuration file.

```
sudo nano /etc/default/hostapd
```

Find the line with #DAEMON_CONF, and replace it with this:

```
DAEMON_CONF="/etc/hostapd/hostapd.conf"
```

### Start it up

Now start up the remaining services:

```
sudo service hostapd start  
sudo service dnsmasq start  
```
### Add routing and masquerade

Edit /etc/sysctl.conf and uncomment this line:
```
net.ipv4.ip_forward=1
```

Add a masquerade for outbound traffic on eth0:
```
sudo iptables -t nat -A  POSTROUTING -o eth0 -j MASQUERADE
```
Save the iptables rule.
```
sudo sh -c "iptables-save > /etc/iptables.ipv4.nat"
```

Edit /etc/rc.local and add this just above "exit 0" to install these rules on boot.
```
iptables-restore < /etc/iptables.ipv4.nat
```
Reboot

Using a wireless device, search for networks. The network SSID you specified in the hostapd configuration should now be present, and it should be accessible with the specified password.

If SSH is enabled on the Raspberry Pi access point, it should be possible to connect to it from another Linux box (or a system with SSH connectivity present) as follows, assuming the `pi` account is present:

```
ssh pi@192.168.4.1
```

By this point, the Raspberry Pi is acting as an access point, and other devices can associate with it. Associated devices can access the Raspberry Pi access point via its IP address for operations such as `rsync`, `scp`, or `ssh`.
