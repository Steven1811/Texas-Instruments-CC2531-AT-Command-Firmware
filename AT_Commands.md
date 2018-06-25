#  AT Commandset

### General

| Command | Parameters | Description                                  | Result |
| ------- | ---------- | -------------------------------------------- | ------ |
| AT      | -          | Returns "OK" for testing communication       | OK     |
| AT+RST  | -          | Resets the device                            | OK     |
| AT+HELP | -          | Prints a help-page of all available commands | OK     |

### IEEE 802.15.4 Radio settings

| Command  | Parameters | Range      | Description                                                  | Result              |
| -------- | ---------- | ---------- | ------------------------------------------------------------ | ------------------- |
| AT+TXPWR | [TX_POWER] | 5 to 28    | Sets or shows the current TX_Power.                          | [TX_POWER]<br />OK  |
| AT+CH    | [CHANNEL]  | 11 to 26   | Sets or shows the current RF channel.                        | [CHANNEL]<br />OK   |
| AT+PID   | [PAN_ID]   | 0 to 65535 | Sets or shows the current pan_id.                            | [PAN_ID]<br />OK    |
| AT+RSSI  | -          | -          | Returns the current received signal strength indicator (RSSI) | {RSSI}<br />OK/FAIL |

### Operation Mode

| Command | Parameters                            | Range                                           | Description                      | Result  |
| ------- | ------------------------------------- | ----------------------------------------------- | -------------------------------- | ------- |
| AT+SEND | [IPV6_ADRESS]<br />[PORT]<br />[DATA] | IPV6_ADRESS<br />0 to 65535<br />256 bytes long | Sends UDP Data to a destination  | OK/FAIL |
| AT+OP   | -                                     | -                                               | Enters UDP server operation mode | OK/FAIL |