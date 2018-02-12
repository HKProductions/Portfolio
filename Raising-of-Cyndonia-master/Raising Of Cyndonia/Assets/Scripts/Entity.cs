using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Entity : MonoBehaviour 
{
	[SerializeField] bool isDead, isPlayer, canAttack, inCombat, canInteract, statusEffect, canRecruit, canRegen, specialAvailable, defenseActive;
	[SerializeField] int level, maxHitPoints, hitPoints, magicPoints, skillPoints, hitPointReg, damage, magicDamage, specialDamage, defense, specialUnlock;
	[SerializeField] string name;
	public Sprite image;

	public RandomEncounter chanceEncounter; //chance that the enemy can be encountered
	public CharacterRole role; //what role does the entity have in the game
	public CharacterWeakness weakness; //The weakness of the entity
	public CharacterStrength invulnerable; //The strengths of the entity
	public AttackType attacks;
	public MagicType magic;

	// Update is called once per frame
	void Update() 
	{

	}

	//for the temp object will copy all stats in prefab of that goblin pre set
	public void AddMember(Entity ent)
	{
		this.name = ent.name;
		this.image = ent.image;
		this.chanceEncounter = ent.chanceEncounter;
		this.role = ent.role;
		this.weakness = ent.weakness;
		this.invulnerable = ent.invulnerable;
		this.weakness = ent.weakness;
		this.level = ent.level;
		this.hitPoints = ent.hitPoints;
		this.maxHitPoints = ent.maxHitPoints;
		this.damage = ent.damage;
		this.magicDamage = ent.magicDamage;
		this.specialDamage = ent.specialDamage;
	}

	//See if the entity is dead
	public bool IsDead 
	{
		get { return isDead; }
		set { isDead = value; }
	}

	//See if the entity is the player
	public bool IsPlayer 
	{
		get{ return isPlayer; }
		set{ isPlayer = value; }
	}

	//See if it's the entity's turn to attack
	public bool CanAttack 
	{
		get{ return canAttack; }
		set{ canAttack = value; }
	}

	//See if the entity is interactable
	public bool CanInteract 
	{
		get{ return canInteract; }
		set{ canInteract = value; }
	}

	//See if the entity has a status effect on them
	public bool StatusEffect 
	{
		get{ return statusEffect; }
		set{ statusEffect = value; }
	}

	//See if you can recruit the entity
	public bool CanRecruit 
	{
		get{ return canRecruit; }
		set{ canRecruit = value; }
	}

	//See if the entity can regenerate health
	public bool CanRegen 
	{
		get{ return canRegen; }
		set{ canRegen = value; }
	}

	//See if the special attack is available
	public bool SpecialAvailable 
	{
		get{ return specialAvailable; }
		set{ specialAvailable = value; }
	}

	//See if the player activated defend
	public bool DefenseActive 
	{
		get{ return defenseActive; }
		set{ defenseActive = value; }
	}

	//See what level the entity is at
	public int Level 
	{
		get{ return level; }
		set{ level = value; }
	}

	//See how much health the entity has
	public int HitPoints 
	{
		get{ return hitPoints; }
		set{ hitPoints = value; }
	}

	//Will be useful for the health bar and level up system
	//so that way we can alter the health level without changing the
	//characters current health
	public int MaxHitPoints 
	{
		get{ return maxHitPoints; }
		set{ maxHitPoints = value; }
	}

	//See how much magic the entity has
	public int MagicPoints 
	{
		get{ return magicPoints; }
		set{ magicPoints = value; }
	}

	//See how many experience points the entity has
	public int SkillPoints 
	{
		get{ return skillPoints; }
		set{ skillPoints = value; }
	}

	//See how much health the entity can regenerate
	public int HitPointReg 
	{
		get{ return hitPointReg; }
		set{ hitPointReg = value; }
	}

	//See how much base level damage the entity can do
	public int Damage 
	{
		get{ return damage; }
		//set{ damage = value; }
	}

	//See how much base level magic attack damage the entity can do
	public int MagicDamage 
	{
		get{ return magicDamage; }
		set{ magicDamage = value; }
	}

	//See how much base level special attack damage the entity can do
	public int SpecialDamage 
	{
		get{ return specialDamage; }
		set{ specialDamage = value; }
	}

	//See how much base level defense entity has
	public int Defense 
	{
		get{ return defense; }
		set{ defense = value; }
	}

	//See how many turns it will take to unlock the special for the entity
	public int SpecialUnlock
	{
		get{ return specialUnlock; }
		set{ specialUnlock = value; }
	}

	//see what the entities name is
	public string Name 
	{
		get{ return name; }
		set{ name = value; }
	}

	public CharacterRole Role 
	{
		get{ return role; }
		set { role = value; }
	}

	public CharacterWeakness Weakness 
	{
		get{ return weakness; }
		set{ weakness = value; }
	}

	public CharacterStrength Invulnerable 
	{
		get{ return invulnerable; }
		set{ invulnerable = value; }
	}

	public AttackType Attacks 
	{
		get{ return attacks; }
		set{ attacks = value; }
	}

	public MagicType Magic 
	{
		get{ return magic; }
		set{ magic = value; }
	}

}

public enum CharacterRole
{
	Mage, Theif, Knight, None
}

public enum AttackType
{
	Melee, Magic, Special, None
}

public enum MagicType
{
	Fire, Ice, Thunder, Dark, Light, Wind, Water, Melee
}

public enum CharacterWeakness
{
	Fire, Ice, Thunder, Dark, Light, Wind, Water, Melee
}

public enum CharacterStrength
{
	Fire, Ice, Thunder, Dark, Light, Wind, Water, Melee
}
