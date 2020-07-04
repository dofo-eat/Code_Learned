/*************************************************************************
	> File Name: test.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月04日 星期六 16时04分17秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include<cjson/cJSON.h>

char text[] = "{\"timestamp\":\"2019-03-03 08:45:57\", \"value\":1}";

int main(int argc, const char *argv[])
{
    cJSON *json, *json_value, *json_timestamp;

    json = cJSON_Parse(text);
    if(NULL == json)
    {
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        return -1;
    }

    json_value = cJSON_GetObjectItem(json, "value");
    if(json_value->type == cJSON_Number)
    {
        printf("value: %d\n", json_value->valueint);
    }

    json_timestamp = cJSON_GetObjectItem(json, "timestamp");
    if(json_timestamp->type == cJSON_String)
    {
        printf("%s\n", json_timestamp->valuestring);
    }

    cJSON_Delete(json);

    return 0;
}
