# block-io-analyzer
block I/O trace data analyzer

1. [blktrace](https://linux.die.net/man/8/blktrace)

    * block device: 하드 디스크나, CD, 플로피 디스크 등의 장치를 말하며, 블록 등의 단위로 데이터를 전송한다.
      * 리눅스 머신의 `/dev` 아래 들어가면 장치 드라이버나 터미널 등 주변 장치들을 나타내는 파일이 있다. `ls -l`을 했을 때, 파일 유형이 `b`로 시작하면 블록 디바이스로 보면 된다.
      
          `brw-rw----  1 root disk      8,   0 Mar  4 00:17 sda`

    * sda(하드디스크 1번)의 blktrace를 저장해 보기
    
        `blktrace -d /dev/sda -o trace -w 30`
        
            * -d Use specified device. May also be given last after options
            * -o File(s) to send output to
            * -w Stop after defined time, in seconds

2. [blkparse](https://linux.die.net/man/1/blkparse)
    
    * blktrace를 blkparse로 분석하여 결과 저장
   
        `blktrace -d /dev/sda -w 30 | blkparse -i - -o ./blktrace.sda.ext.iozone`
        
            * -i Input file containing trace data, or '-' for stdin
            * -o Output file. If not given, output is stdout
