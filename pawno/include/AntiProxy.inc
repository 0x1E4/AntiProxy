/*
Lets make this an include XD
Made by: GnikLlort

Please don't remove this copyright 
Because you are so nice :*
*/

//forward start
forward MyHttpResponse(playerid, response_code, data[]);
forward OnPlayerUseProxy(playerid); //called when player use proxy/vpn, you can use this on your gamemode/filterscript.
//forward end

#include <a_samp>
#include <a_http>

public OnPlayerConnect(playerid)
{
	new ip[16], string[59];
	GetPlayerIp(playerid, ip, sizeof ip);
	format(string, sizeof string, "www.shroomery.org/ythan/proxycheck.php?ip=%s", ip);
	HTTP(playerid, HTTP_GET, string, "", "MyHttpResponse");
	#if defined ap_OnPlayerConnect
		ap_OnPlayerConnect(playerid)
	#endif
    return 1;	
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define ALS_OnPlayerConnect
#endif

#define OnPlayerConnect ap_OnPlayerConnect

#if defined ap_OnPlayerConnect
    forward ap_OnPlayerConnect(playerid);
#endif

public MyHttpResponse(playerid, response_code, data[])
{
	new name[MAX_PLAYERS],string[256];
	new ip[16];
	GetPlayerName(playerid, name, sizeof(name));
	GetPlayerIp(playerid, ip, sizeof ip);
	if(strcmp(ip, "127.0.0.1", true) == 0) return 1;
	
	if(response_code == 200)
	{	
		if(data[0] == 'Y')
		{
			CallLocalFunction("OnPlayerUseProxy", "i", playerid);
		}
	}
	else
	{
		print("Exception throw at: Invalid or Dead (URL/Link)");
	}
	#if defined ap_MyHttpResponse
		ap_MyHttpResponse(playerid, response_code, data[]);
	#endif
	return 1;
}

#if defined _ALS_MyHttpResponse
    #undef MyHttpResponse
#else
    #define ALS_MyHttpResponse
#endif

#define MyHttpResponse ap_MyHttpResponse

#if defined ap_MyHttpResponse
    forward ap_MyHttpResponse(playerid, response_code, data[]);
#endif
