using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BattleUI : MonoBehaviour 
{
	Entity entInfo;
	public PlayerMenu curMenu; //current menu player is on
	public GameObject choices, skills, invent, party, descrip, target; //different panels
	public GameObject targetChoice; //The choice for the target to attack
	//public Text attack, skill, inventory, escape, skill1, skill2, skill3, skill4; //different text
	public Text win, lose, descripe;
	public Text[] partyName, targetName;
	public int curChoice, targetUnit; //input key for choosing
	public BattleStateManager BSM;

	void Awake()
	{
		entInfo = gameObject.GetComponent<Entity> ();
	}
			
	// Use this for initialization
	void Start() 
	{
		ChangePanel(PlayerMenu.Description);
		//curMenu = PlayerMenu.Choice;
	}
	
	// Update is called once per frame
	void Update() 
	{
		//gets input when pressed keys 1-4 down
		if (Input.GetKeyDown (KeyCode.Alpha1) || Input.GetKeyDown (KeyCode.Keypad1)) 
			curChoice = 1;
		
		else if (Input.GetKeyDown (KeyCode.Alpha2) || Input.GetKeyDown (KeyCode.Keypad2)) 
			curChoice = 2;
		
		else if (Input.GetKeyDown (KeyCode.Alpha3) || Input.GetKeyDown (KeyCode.Keypad3)) 
			curChoice = 3;
		
		else if (Input.GetKeyDown (KeyCode.Alpha4) || Input.GetKeyDown (KeyCode.Keypad4)) 
			curChoice = 4;
		
		else //if a different key is pressed then sets curChoice as zero and does nothing
			curChoice = 0;

		//if current choice is 1-4 then it will call the player choice function
		if(curChoice >= 1 && curChoice <= 5)
			PlayerChoice(curChoice);

	}

	//the change panel function
	public void ChangePanel(PlayerMenu menu)
	{
		curMenu = menu;
		curChoice = 0;
		switch (menu)
		{
			//the beginning panel
			case PlayerMenu.Choice:				
				choices.gameObject.SetActive(true);
				skills.gameObject.SetActive(false);
				invent.gameObject.SetActive(false);
				party.gameObject.SetActive(true);
				descrip.gameObject.SetActive(false);
				target.gameObject.SetActive(false);
				break;

			//the skills panel
			case PlayerMenu.Skill:
				choices.gameObject.SetActive(false);
				skills.gameObject.SetActive(true);
				invent.gameObject.SetActive(false);
				party.gameObject.SetActive(true);
				descrip.gameObject.SetActive(false);
				target.gameObject.SetActive(false);
				break;			

			//the inventory panel
			case PlayerMenu.Inventory:
				choices.gameObject.SetActive(false);
				skills.gameObject.SetActive(false);
				invent.gameObject.SetActive(true);
				party.gameObject.SetActive(true);
				descrip.gameObject.SetActive(false);
				target.gameObject.SetActive(false);
				break;

			//the description of actions panel
			case PlayerMenu.Description:
				choices.gameObject.SetActive(false);
				skills.gameObject.SetActive(false);
				invent.gameObject.SetActive(false);
				party.gameObject.SetActive(true);
				descrip.gameObject.SetActive(true);
				target.gameObject.SetActive(false);
				break;

			case PlayerMenu.Target:
				choices.gameObject.SetActive(false);
				skills.gameObject.SetActive(false);
				invent.gameObject.SetActive(false);
				party.gameObject.SetActive(true);
				descrip.gameObject.SetActive(false);
				target.gameObject.SetActive(true);
				break;
							
		}
	}

	//allows player to decide on what action to take based off of the panel
	public void PlayerChoice(int choice)
	{
		switch (choice)
		{
			case 1:
				if (curMenu == PlayerMenu.Choice) 
				{
					ChangePanel (PlayerMenu.Target);
				} 
				else if (curMenu == PlayerMenu.Skill) 
				{
					//Skill 1 used description
					ChangePanel(PlayerMenu.Target);
				} 	
				else if (curMenu == PlayerMenu.Inventory)
				{
					//Item 1 used description
					ChangePanel(PlayerMenu.Description);
				}
				else if (curMenu == PlayerMenu.Description)
				{
					//Changes back to choice if next party member
					ChangePanel(PlayerMenu.Choice);
					++BSM.unitNum; //go to the next units turn
				}
				else if (curMenu == PlayerMenu.Target)
				{
					//Target number 1 used description
					targetUnit = curChoice - 1; //choose to target the first unit in list
					ChangePanel(PlayerMenu.Description);
				}
				break;

			case 2:
				if (curMenu == PlayerMenu.Choice) 
				{
					//Skill Menu
					ChangePanel (PlayerMenu.Skill);
				} 
				else if (curMenu == PlayerMenu.Skill) 
				{
					//Skill 2 used description
					ChangePanel (PlayerMenu.Target);
				} 
				else if (curMenu == PlayerMenu.Inventory)
				{
					//Item 2 used description
					ChangePanel(PlayerMenu.Description);
				}
				else if (curMenu == PlayerMenu.Target)
				{
					//Target number 2 used description
					targetUnit = curChoice - 1; //choose to target the first unit in list
					ChangePanel(PlayerMenu.Description);
				}
				break;

			case 3:
				if (curMenu == PlayerMenu.Choice) 
				{
					//Inventory Menu
					ChangePanel (PlayerMenu.Inventory);
				} 

				else if (curMenu == PlayerMenu.Skill) 
				{
					//Skill 3 used description
					ChangePanel (PlayerMenu.Choice);
				} 
				else if (curMenu == PlayerMenu.Inventory)
				{
					//Item 3 used description
					ChangePanel(PlayerMenu.Description);
				}
				else if (curMenu == PlayerMenu.Target)
				{
					//Target number 3 used description
					targetUnit = curChoice - 1; //choose to target the first unit in list
					ChangePanel(PlayerMenu.Description);
				}
				break;

			case 4:
				if (curMenu == PlayerMenu.Choice) 
				{
					//Block description
					ChangePanel (PlayerMenu.Description);
				} 
				else if (curMenu == PlayerMenu.Skill) 
				{
					//Skill 4 used description
					ChangePanel (PlayerMenu.Target);
				}
				else if (curMenu == PlayerMenu.Inventory)
				{
					//Item 4 used description
					ChangePanel(PlayerMenu.Choice);
				}
				else if (curMenu == PlayerMenu.Target)
				{
					//Target number 4 used description
					targetUnit = curChoice - 1; //choose to target the first unit in list
					ChangePanel(PlayerMenu.Description);
				}
				break;
		}
	}

	public int Target 
	{
		get{ return targetUnit; }
	}

	public PlayerMenu CurMenu 
	{
		get{ return curMenu; }
	}
}

//player menu panels
public enum PlayerMenu
{
	Choice, Target, Skill, Inventory, Description
}