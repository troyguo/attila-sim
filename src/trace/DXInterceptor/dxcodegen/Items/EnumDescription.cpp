////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Items/SmartPointer.h"
#include "Items/EnumDescriptionMember.h"
#include "Items/EnumDescription.h"

using namespace std;
using namespace dxcodegen::Items;

////////////////////////////////////////////////////////////////////////////////

EnumDescription::EnumDescription()
{
}

////////////////////////////////////////////////////////////////////////////////

EnumDescription::~EnumDescription()
{
}

////////////////////////////////////////////////////////////////////////////////

void EnumDescription::SetName(const string& name)
{
  m_name = name;
}

////////////////////////////////////////////////////////////////////////////////

string& EnumDescription::GetName()
{
  return m_name;
}

////////////////////////////////////////////////////////////////////////////////

void EnumDescription::AddMember(const EnumDescriptionMemberPtr member)
{
  pair<map<string, string>::iterator, bool> ins_res;
  ins_res = m_mapMembers.insert(pair<string, string>(member->GetName(), member->GetName()));
  if (ins_res.second)
  {
    m_lstMembers.push_back(member);
  }
}

////////////////////////////////////////////////////////////////////////////////

unsigned int EnumDescription::GetMembersCount()
{
  return (unsigned int) m_lstMembers.size();
}

////////////////////////////////////////////////////////////////////////////////

EnumDescriptionMemberPtr EnumDescription::GetMember(unsigned int position)
{
  return m_lstMembers[position];
}

////////////////////////////////////////////////////////////////////////////////