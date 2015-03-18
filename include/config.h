// various constants and parameters

// type of object
#define TYPE_CONTAINER "container"
#define TYPE_LPROCESS "lprocess"

// period before collect usage again
#define USAGE_CHECK_PERIOD 0.5

// cgroup path
#define BASE_URL "/sys/fs/cgroup/"
#define CPUACCT_URL "cpuacct/"
#define CPU_URL "cpu/"
#define CPUSET_URL "cpuset/"
#define DOCKER_URL "docker/"
#define CPU_STAT_FILE "cpuacct.stat"
#define CPU_SHARES_FILE "cpu.shares"
#define CPUSET_FILE "cpuset.cpus"
#define CPU_CFS_QUOTA_FILE "cpu.cfs_quota_us"
#define CPU_CFS_PERIOD_FILE "cpu.cfs_period_us"

// network statistics files
#define NET_TX_FILE "/sys/devices/virtual/net/eth0/statistics/tx_bytes"
#define NET_RX_FILE "/sys/devices/virtual/net/eth0/statistics/rx_bytes"
