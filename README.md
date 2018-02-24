# scoreboard
Code for the scoreboard 


needed packages:
-wiringpi:  sudo apt-get install wiringpi

To Start the wifi-Adapter 
            sudo hostapd -dd /etc/hostapd/hostapd.conf

            Password: YourPassPhrase


#changes in rc.local
sudo iptables -A INPUT -p tcp -s localhost --dport 80 -j ACCEPT
