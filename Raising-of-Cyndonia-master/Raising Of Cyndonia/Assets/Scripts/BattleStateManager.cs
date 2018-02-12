using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BattleStateManager : MonoBehaviour 
{
	public StatesOfBattle currentState; //state of the battle
	public GameObject player, enemy, playerUnit, enemyUnit, battleCamera; //player, enemy, and the party of player and enemy game objects
	//not sure we will be using these yet
	//public PlayerParty playerUnit; 
	//public EnemyParty enemyUnit;
	//public List<GameObject> playersUnits = new List<GameObject>();
	//public List<GameObject> enemysUnits = new List<GameObject>();
	public int unitNum;
	public BattleUI bUI;
	//public EventManager eventM;

	// Use this for initialization
	void Start() 
	{
		unitNum = 0; //which unit will be going
		player = GameObject.FindGameObjectWithTag("Player"); //sets up the player will have a setup for enemy as well
		currentState = StatesOfBattle.Start; //sets the current state to start
	}
	
	// Update is called once per frame
	void Update() 
	{		
		//player = GameObject.FindGameObjectWithTag("Player");
		if (gameObject.GetComponent<EventManager>().encounteredEnemies.Count <= 0)
		{
			currentState = StatesOfBattle.Win;
		}
		else if (player.GetComponent<PlayerInfo>().allParty.Count <= 0)
		{
			currentState = StatesOfBattle.Lose;
		}
		//Debug.Log (currentState);
		switch (currentState)
		{
			case (StatesOfBattle.Start):
				//setup battle function
				bUI.ChangePanel(PlayerMenu.Choice);

				currentState = StatesOfBattle.PlayerTurn;
				break;

			case (StatesOfBattle.PlayerTurn): //players turn goes through until all party members have done something
			
				//Sets it so that as long as unitNum is less than the list size of the player then the player can chose there choices
				if (unitNum > (player.GetComponent<PlayerInfo>().allParty.Count - 1)) 
				{
					unitNum = 0; //resets unitNum to 0 for enemy
					currentState = StatesOfBattle.EnemyTurn; //changes to enemies turn
				}
				else 
				{
					playerUnit = player.GetComponent<PlayerInfo>().allParty[unitNum]; //grabs a unit from the players party list
					
					//These two if else statements are supposed to define what type of attack the player is going to do
					if (bUI.CurMenu == PlayerMenu.Target)//Need to update this for just melee attack this is just for testing
					{
						playerUnit.GetComponent<Entity>().Attacks = AttackType.Melee;
					}
					else if (bUI.CurMenu == PlayerMenu.Skill)
					{
						playerUnit.GetComponent<Entity>().Attacks = AttackType.Magic;
					}
					//The only way the attack script will activate is if the script is in the description menu and the player has an attack set to it
					if (bUI.CurMenu == PlayerMenu.Description && (playerUnit.GetComponent<Entity>().Attacks == AttackType.Melee || playerUnit.GetComponent<Entity>().Attacks == AttackType.Magic)) 
					{
						enemy = gameObject.GetComponent<EventManager>().encounteredEnemies[bUI.Target]; //Get the target the player will attack
						Debug.Log("Object Attacking: " + playerUnit);
						playerUnit.GetComponent<AttackComponent>().Attack (enemy); //Deal damage to the enemy
						playerUnit.GetComponent<Entity>().Attacks = AttackType.None; //Reset the attack type to nothing so that this statement doesn't execute again
					}
				}
				break;

			case (StatesOfBattle.EnemyTurn): //enemies turn goes through until all enemies have done something
				//Sets it so that as long as unitNum is less than the list size of the enemy then the enemy can chose there choices
				if (unitNum > (gameObject.GetComponent<EventManager>().encounteredEnemies.Count - 1))
				{
					unitNum = 0; //resets unitNum to 0 for player
					currentState = StatesOfBattle.PlayerTurn; //changes to players turn
				}
				else
				{					
					enemyUnit = gameObject.GetComponent<EventManager>().encounteredEnemies[unitNum]; //grabs a unit from the eventmanager's encounter list

					enemyUnit.GetComponent<Entity>().Attacks = AttackType.Melee;
					enemyUnit.GetComponent<AttackComponent>().Attack(player.GetComponent<PlayerInfo>().allParty[0]); //Deal damage to the player
					enemyUnit.GetComponent<Entity>().Attacks = AttackType.None; //Reset the attack type to nothing so that this statement doesn't execute again
					unitNum++;
					/*if (bUI.CurMenu == PlayerMenu.Target)//Need to update this for just melee attack this is just for testing
					{
						enemyUnit.GetComponent<Entity>().Attacks = AttackType.Melee;
					}
					else if (bUI.CurMenu == PlayerMenu.Skill)
					{
						enemyUnit.GetComponent<Entity>().Attacks = AttackType.Magic;
					}
					//The only way the attack script will activate is if the script is in the description menu and the enemy has an attack set to it
					if (bUI.CurMenu == PlayerMenu.Description && ((enemyUnit.GetComponent<Entity>().Attacks == AttackType.Melee) || (enemyUnit.GetComponent<Entity>().Attacks == AttackType.Magic)))
					{
						enemyUnit.GetComponent<AttackComponent>().Attack(player.GetComponent<PlayerInfo>().allParty[bUI.Target]); //Deal damage to the player
						enemyUnit.GetComponent<Entity>().Attacks = AttackType.None; //Reset the attack type to nothing so that this statement doesn't execute again
					}*/
				}
				break;

			//case (StatesOfBattle.CalcDamage): //calculates the damage done
			//	break;

			case (StatesOfBattle.Lose): //set up if player loses
				Debug.Log("Loser");

				//pauses the game so that the player can see the end game message
				bUI.lose.gameObject.SetActive(true);

				StartCoroutine(ShowLoseText());
				/*gameObject.GetComponent<EventManager>().ExitBattle(); //lets player exit battle and walk around
				currentState = StatesOfBattle.Start; //resets the BattleState script
				unitNum = 0; //resets chosen unit*/
				break;

			case (StatesOfBattle.Win): //set up if player wins
				Debug.Log("Yah, okay you won good job I guess");
				bool i = true;
				if (Input.GetKeyDown(KeyCode.Space))
				{
					i = false;
				}
				//pauses the game so that the player can see the end game message
				bUI.win.gameObject.SetActive(i);
				StartCoroutine(ShowWinText(i));
				/*gameObject.GetComponent<EventManager>().ExitBattle(); //lets player exit battle and walk around
				currentState = StatesOfBattle.Start; //resets the BattleState script
				unitNum = 0; //resets chosen unit*/
				break;
		}
	}

	IEnumerator ShowWinText(bool i)
	{
		bUI.win.gameObject.SetActive(true);
		yield return new WaitForSeconds(3);
		gameObject.GetComponent<EventManager>().ExitBattle(); //lets player exit battle and walk around
		currentState = StatesOfBattle.Start; //resets the BattleState script
		unitNum = 0; //resets chosen unit
		bUI.win.gameObject.SetActive(false);
	}
	IEnumerator ShowLoseText()
	{
		bUI.lose.gameObject.SetActive(true);
		yield return new WaitForSeconds(3);
		gameObject.GetComponent<EventManager>().ExitBattle(); //lets player exit battle and walk around
		currentState = StatesOfBattle.Start; //resets the BattleState script
		unitNum = 0; //resets chosen unit
		bUI.lose.gameObject.SetActive(false);
	}

	//was for changeing states have not finished it
	void ChangeState()
	{
	}
		
}

public enum StatesOfBattle
{
	//Later will add animations here as well if we have time
	Start, PlayerTurn, EnemyTurn, CalcDamage, Lose, Win
}
