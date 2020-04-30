#include"JsonHelper.h"
#include "Messages.h"
#include<QDebug>
#include<QFile>
void JsonHelper::Test()
{
	node n;
	int a = sizeof(n);

	QFile file("./config.json");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	cJSON* jsonObj = cJSON_Parse(file.readAll().data());
	cJSON_GetObjectItem(jsonObj, "");
	file.close();

	cJSON_Delete(jsonObj);
	
	/*Test4Json json;
	cJSON* root;
	root = cJSON_CreateObject();
	cJSON_AddNumberToObject(root, "a", json.a);
	cJSON_AddStringToObject(root, "name", json.name);
	char* jsonText = cJSON_PrintUnformatted(root);
	qDebug() << jsonText;
	delete root;*/
}
