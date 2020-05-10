using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(AudioSource))]
public class EventManager : MonoBehaviour 
{
	public GameObject exploreCamera, battleCamera, player, enPos, plPos, emptyPos1, emptyPos2; //sets up game objects
	public List<GameObject> allEnemies = new List<GameObject>(); //creates a list of enemies
	public int numberOfEnemies, whichEnemy; //random numbers for number of enemies and which enemies
	public string name;
	//public List<SkillsComponent> allSkills = new List<SkillsComponent>(); //creates a list of skills
	//public GameObject tempEnt, 
	public List<GameObject> encounteredEnemies = new List<GameObject>(); //temp game object was using to switch goblins and mess with
	public BattleUI bUI; //battle UI
	[SerializeField] bool isBoss;
	AudioSource audio;

	public Transform[] enemyBPosition; //the positions enemies can be in
	public Transform[] playerBPosition; //the positions the player's party can be in

	public AudioClip otherClip, End;

	// Use this for initialization
	void Start() 
	{
		gameObject.GetComponent<BattleStateManager>().enabled = false;
		battleCamera.GetComponent<BattleUI>().win.gameObject.SetActive(false);
		battleCamera.GetComponent<BattleUI>().lose.gameObject.SetActive(false);
		//exploreCamera = GameObject.FindGameObjectWithTag("MainCamera");
		exploreCamera.SetActive(true); //turns on exploring player camera
		//battleCamera = GameObject.FindGameObjectWithTag("BattleCamera");
		battleCamera.SetActive(false); //turns off battle camera
		player = GameObject.FindGameObjectWithTag("Player");
		audio = GetComponent<AudioSource>();
	}
	
	// Update is called once per frame
	void Update() 
	{
		if (battleCamera == false)
			encounteredEnemies.Clear();
	}

	public void BattleStart(RandomEncounter rEncounter)
	{
		//isBoss = GameObject.FindGameObjectWithTag("Boss").GetComponent<EncounterInstance>().BossStage;
		numberOfEnemies = Random.Range(0, 3); //roles a random number between 0-2 on how many enemies you will encounter where 0 = 1

		exploreCamera.SetActive(false); //sets exploration player camera off
		battleCamera.SetActive(true); //turns the battle camera on for a battle
		//encounteredEnemies = GetRandomEnemy(EnemiesInLocation(rEncounter)); //gets the enemy you will encounter

		//Debug.Log(encounteredEnemies.name);

		player.GetComponent<PlayerMove>().inCombat = true; //makes it so player cant move in combat
		if (player.GetComponent<PlayerMove>().inCombat)
		{
			gameObject.GetComponent<BattleStateManager>().enabled = true;
			audio.clip = otherClip;
			audio.Play();

		}

		for (int i = 0; i < 3; i++)
		{
			//plPos = Instantiate(player.GetComponent<PlayerInfo>().allParty[i], playerBPosition[i].transform.position, Quaternion.identity) as GameObject; //places enemy in position 2
			player.GetComponent<PlayerInfo>().allParty[i].transform.position = playerBPosition[i].transform.position;
			//gets the player and player name
			battleCamera.GetComponent<BattleUI>().partyName[2-i].text = player.GetComponent<PlayerInfo>().allParty[i].GetComponent<Entity>().Name;

			if (GameObject.FindGameObjectWithTag("Boss").GetComponent<EncounterInstance>().BossStage == true)
			{
				enPos = Instantiate(allEnemies[i], enemyBPosition[i].transform.position, Quaternion.identity) as GameObject; //places random enemy in enemy position
				encounteredEnemies.Add(enPos); //adds Boss to list

				//gets the enemy targets name
				battleCamera.GetComponent<BattleUI>().targetName[i].text = i + 1 + ": " + enPos.GetComponent<Entity>().Name;
				StartCoroutine(DelaySpawn());
			}
			/*else if (i <= numberOfEnemies && isBoss == false)
			{		
				whichEnemy = Random.Range(0, 5); //roles a random number of which random enemy in list
				//Debug.Log(encounteredEnemies[whichEnemy].name);
				//enPos = Instantiate(encounteredEnemies[whichEnemy], enemyBPosition[i].transform.position, Quaternion.identity) as GameObject;
				Debug.Log(allEnemies[whichEnemy].name); //states what random enemy it is
				//encounteredEnemies.Add(allEnemies[whichEnemy]);
				//encounteredEnemies[i] = allEnemies[whichEnemy]; 
				enPos = Instantiate(allEnemies[whichEnemy], enemyBPosition[i].transform.position, Quaternion.identity) as GameObject; //places random enemy in enemy position
				encounteredEnemies.Add(enPos);	//adds random range of enemies to list	
				//gets the enemy targets name
				battleCamera.GetComponent<BattleUI>().targetName[i].text = enPos.GetComponent<Entity>().Name;
			}*/
		}


		/*
		//rEncounter is based off of the tile and how it is set to uncommon, common, or epic and then the gameobjects themselves have encounter rates 
		encounteredEnemies = GetRandomEnemy(EnemiesInLocation(rEncounter)); //make this enemy random as well

		enPos = Instantiate(emptyPos2, enemyBPosition[0].transform.position, Quaternion.identity) as GameObject; //places enemy in position 2

		enPos.transform.parent = enemyBPosition[0]; //places the sprite where the enemy position 2 is
		tempEnt = enPos.AddComponent<Entity>() as Entity; //temp entity in which it will switch between different goblins based off of encounter rate
		tempEnt.AddMember(GetRandomEnemy(EnemiesInLocation(rEncounter)));
		enPos.GetComponent<SpriteRenderer>().sprite = encounteredEnemies.image;
		*/

	}

	IEnumerator DelaySpawn()
	{
		yield return new WaitForSeconds(1);
	}

	public void ExitBattle()
	{
		gameObject.GetComponent<BattleStateManager>().enabled = false;
		exploreCamera.SetActive(true); //turns on exploring player camera
		battleCamera.SetActive(false); //turns off battle camera
		player.GetComponent<PlayerMove>().inCombat = false; //makes it so player can move outside of combat
		audio.Pause();
		audio.clip = End;
		audio.PlayDelayed(0.05f);
		audio.loop = false;
	}

	public void RemoveEnemy(GameObject enemy)
	{
		
		/*for (int i = 0; i < 3; i++)
		{
			if (battleCamera.GetComponent<BattleUI>().targetName[i].text == encounteredEnemies[i].GetComponent<Entity>().Name)
			{
				battleCamera.GetComponent<BattleUI>().targetName[i].text = " ";
			}
			else if (
			{
				
			}
		}*/



			//if (battleCamera.GetComponent<BattleUI>().targetName[i].text == enemy.GetComponent<Entity>().Name)
			//{
			//	battleCamera.GetComponent<BattleUI>().targetName.Remove(battleCamera.GetComponent<BattleUI>().targetName[0]);
				//battleCamera.GetComponent<BattleUI>().targetName[i].text = encounteredEnemies[j].GetComponent<Entity>().Name;
				//j++;
			//}
			//battleCamera.GetComponent<BattleUI>().targetName[i].text = encounteredEnemies[j].GetComponent<Entity>().Name;

		//}
		encounteredEnemies.Remove(enemy);
		battleCamera.GetComponent<BattleUI>().targetName[0].text = battleCamera.GetComponent<BattleUI>().targetName[1].text;
		battleCamera.GetComponent<BattleUI>().targetName[1].text = battleCamera.GetComponent<BattleUI>().targetName[2].text;
		battleCamera.GetComponent<BattleUI>().targetName[2].text = " ";


		//battleCamera.GetComponent<BattleUI>().targetName[i].text = enPos.GetComponent<Entity>().Name;

		//battleCamera.GetComponent<BattleUI>().targetName[encounteredEnemies.Count].text = enPos.GetComponent<Entity>().Name;
	}



	//below is used for if there is an encounter rate for each gameObject

	//used for checking enemies that can be encountered
	/*public List<GameObject> EnemiesInLocation(RandomEncounter rEncounter)
	{
		List<GameObject> findEnemy = new List<GameObject>(); //creates the list for enemies
		foreach (GameObject enemy in allEnemies) //gets an encounter rate and what the enemy will be
		{
			if (enemy.GetComponent<Entity>().chanceEncounter == rEncounter) //looks for the enemy in the list
			{
				findEnemy.Add(enemy);
				Debug.Log(enemy.name);
			}
		}
		return findEnemy;
		
	}

	//gets the random enemy that is in the enemy list
	public GameObject GetRandomEnemy(List<GameObject> enemyList)
	{
		GameObject eAI = new GameObject(); //enemy AI entity
		int enemyNum = Random.Range(0, enemyList.Count - 1); //which enemy you will encounter
		eAI = enemyList[enemyNum]; 
		return eAI;
	}*/
}
