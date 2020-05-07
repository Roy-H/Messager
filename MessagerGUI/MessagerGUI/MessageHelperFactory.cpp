//#include "MessageHelperFactory.h"
//
//
//IMessageHelper* MessageHelperFactory::GetHelper(int id)
//{
//	if (mAllMessageHelpers.find(id) != mAllMessageHelpers.end())
//	{
//		return mAllMessageHelpers[id];
//	}
//	return nullptr;
//}
//
////turn helper from helper pool id exist
//IMessageHelper* MessageHelperFactory::CreateHelper(int id)
//{
//	if (mAllMessageHelpers.find(id) != mAllMessageHelpers.end())
//	{
//		return mAllMessageHelpers[id];
//	}
//	return nullptr;
//}
//
//void MessageHelperFactory::ClearAllMessageHelpers()
//{
//	for (int i = 0; i < mAllMessageHelpers.size(); i++)
//	{
//		delete mAllMessageHelpers[i];
//	}
//	mAllMessageHelpers.clear();
//}
//
//void MessageHelperFactory::LoadHelperFromConfigFile()
//{
//	ClearAllMessageHelpers();
//	//create helper and add it to collection
//}
//
////run this fun in main thread
//void MessageHelperFactory::LoadHelperDefault()
//{
//	ClearAllMessageHelpers();
//	//create helper and add it to collection
//	mAllMessageHelpers[1] = new MessageHelper();
//	mAllMessageHelpers[2] = new TestMessageHelper();
//}