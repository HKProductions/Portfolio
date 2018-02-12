using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class SkillsComponent : MonoBehaviour 
{
	Entity entStat; //gets the entity's stats
	public SkillType sType; //determines the type of skill used
	[SerializeField] string skillName, skillDescription;
	[SerializeField] int skillID, skillPower, skillCost; 


	// Use this for initialization
	void Start()
	{
		
	}
	
	// Update is called once per frame
	void Update() 
	{
		
	}

	public string SkillName
	{
		get{return skillName;}
		set{skillName = value;}
	}

	public string SkillDescription
	{
		get{return skillDescription;}
		set{skillDescription = value;}
	}

	public int SkillID
	{
		get{return skillID;}
		set{skillID = value;}
	}

	public int SkillPower
	{
		get{return skillPower;}
		set{skillPower = value;}
	}

	public int SkillCost
	{
		get{return skillCost;}
		set{skillCost = value;}
	}
}

//allows for melee type, range type, and magic type of skills
public enum SkillType
{
	Melee, Range, Magic
}