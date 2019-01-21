# AntiProxy
Detect user when they're using proxy  to join a server (Useful when player got ban and wanted to rejoin) 

## Usage

```
public OnPlayerUseProxy(playerid)
{
    static string[128], pIP[64];
    SendClientMessage(playerid, -1, "You are banned from server because try login using VPN/Proxy");

    GetPlayerIp(playerid, pIP, sizeof(pIP));
    format(string, sizeof(string),"banip %s", type); 
    SendRconCommand(string); 
    SendRconCommand("reloadbans");
    return 1;
}
```
