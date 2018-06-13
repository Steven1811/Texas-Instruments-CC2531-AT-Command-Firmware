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
| AT+SCH   | [CHANNEL]  | 11 to 26   | Sets or shows the current RF channel.                        | [CHANNEL]<br />OK   |
| AT+PID   | [PAN_ID]   | 0 to 65535 | Sets or shows the current pan_id.                            | [PAN_ID]<br />OK    |
| AT+RSSI  | -          | -          | Returns the current received signal strength indicator (RSSI) | {RSSI}<br />OK/FAIL |

### Operation Mode

| Command | Parameters               | Range                         | Description                 | Result  |
| ------- | ------------------------ | ----------------------------- | --------------------------- | ------- |
| AT+MODE | [MODE]<br />[SERVERMODE] | TCP or UDP<br />TRUE or FALSE | Sets the mode for operation | OK/FAIL |
| AT+OP   | -                        | -                             | Enters operation mode       | OK/FAIL |