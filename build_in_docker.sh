#!/bin/bash

pushd target/debs/bookworm
sudo apt-get install -y libhiredis0.14 libhiredis-dev
sudo apt-get install -y libzmq5 libzmq3-dev
sudo apt-get install -y libdbus-1-3

# Install libnl3
sudo dpkg -i libnl-3-200_*.deb
sudo dpkg -i libnl-3-dev_*.deb
sudo dpkg -i libnl-genl-3-200_*.deb
sudo dpkg -i libnl-genl-3-dev_*.deb
sudo dpkg -i libnl-route-3-200_*.deb
sudo dpkg -i libnl-route-3-dev_*.deb
sudo dpkg -i libnl-nf-3-200_*.deb
sudo dpkg -i libnl-nf-3-dev_*.deb
sudo dpkg -i libnl-cli-3-200_*.deb
sudo dpkg -i libnl-cli-3-dev_*.deb

# Install libteam
sudo apt-get install -y libdbus-1-3
sudo dpkg -i libteam5_*.deb
sudo dpkg -i libteamdctl0_*.deb
sudo dpkg -i libteam-utils_*.deb
sudo dpkg -i libteam-dev_*.deb

sudo dpkg -i libyang_*.deb
sudo dpkg -i libyang-*.deb

# Install common library
sudo dpkg -i libswsscommon_1.0.0_amd64.deb
sudo dpkg -i libswsscommon-dev_1.0.0_amd64.deb
sudo dpkg -i libsaivs_*.deb
sudo dpkg -i libsaivs-dev_*.deb
sudo dpkg -i libsairedis_*.deb
sudo dpkg -i libsairedis-dev_*.deb
sudo dpkg -i libsaimetadata_*.deb
sudo dpkg -i libsaimetadata-dev_*.deb
sudo dpkg -i syncd-vs_*.deb

sudo dpkg -i libdashapi*.deb
popd

# Install gtest, gmock, and lcov.
apt-get install -y libgtest-dev
apt-get install -y libgmock-dev

# Install and start Redis
sudo pip install --upgrade pip
cat > base-tooling-requirements.txt <<-EOF
Pympler==0.8 --hash=sha256:f74cd2982c5cd92ded55561191945616f2bb904a0ae5cdacdb566c6696bdb922
EOF
sudo pip install --require-hashes -r base-tooling-requirements.txt
sudo apt-get install -y redis-tools=5:7.0.15-1~deb12u5
sudo apt-get install -y redis-server=5:7.0.15-1~deb12u5
sudo sed -i 's/notify-keyspace-events ""/notify-keyspace-events AKE/' /etc/redis/redis.conf
sudo sed -ri 's/^# unixsocket/unixsocket/' /etc/redis/redis.conf
sudo sed -ri 's/^unixsocketperm .../unixsocketperm 777/' /etc/redis/redis.conf
sudo sed -ri 's/redis-server.sock/redis.sock/' /etc/redis/redis.conf
sudo sed -ri 's/^databases [0-9]+/databases 64/g' /etc/redis/redis.conf
sudo service redis-server restart
