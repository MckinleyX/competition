import java.util.Scanner;
import java.util.HashMap;
import java.io.File;
import java.io.FileNotFoundException;
public class PonyMon
{
	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner input = new Scanner(new File("input.txt"));
		int numPonies = input.nextInt();
		HashMap<String,pony> map = new HashMap<String,pony>(numPonies);
		for(int ii = 0; ii < numPonies; ii++)
		{
			String name = input.next();
			char type = input.next().charAt(0);
			char weak = input.next().charAt(0);
			char resist = input.next().charAt(0);
			short hp = (short)input.nextInt();
			attack[] att = new attack[2];
			for(int jj = 0; jj < 2; jj++)
			{
				input.next();//Attack name
				att[jj] = new attack(type, (short)input.nextInt(), (short)input.nextInt());
			}
			map.put(name, new pony(name, type, weak, resist, hp, att[0], att[1]));
		}
		int numBattles = input.nextInt();
		for(int ii = 0; ii < numBattles; ii++)
		{
			short power = 0;
			short turn = 1;
			pony p1 = map.get(input.next());
			pony p2 = map.get(input.next());
			p1.reset();
			p2.reset();
			do
			{
				pony tmp = p1;
				p1 = p2;
				p2 = tmp;
				if(turn < 11)
				{
					turn++;
					power = (short)(turn/2);
				}
				//System.out.println(p2.name + " attacks " + p1.name + " with " + p2.fight(power).rdamage + " damage.");
			}while(p1.getHit(p2.fight(power)));
			System.out.println(p2.name + " defeats " + p1.name + " with " + p2.hp + " HP remaining.");
		}
	}
			
}
class pony
{
	public String name;
	public char type;
	public char weak;//weakness
	public char resist;//resistance
	public short hp;
	public short maxhp;
	public attack att_a;
	public attack att_b;
	public pony(String name, char type, char weak, char resist, short hp, attack att_a, attack att_b)
	{
		this.name = name;
		this.type = type;
		this.weak = weak;
		this.resist = resist;
		this.maxhp = hp;
		this.hp = hp;
		this.att_a = att_a;
		this.att_b = att_b;
	}
	public boolean getHit(attack att)//returns true if hp > 0
	{
		if(att.type == weak)
		{
			hp -= (att.rdamage*2);
		}
		else if(att.type == resist)
		{
			hp -= (att.rdamage/2);
		}
		else
		{
			hp -= att.rdamage;
		}
		return hp > 0;
	}
	public void reset()
	{
		hp = maxhp;
	}
	public attack fight(short power)
	{
		if(att_b.power <= power)
			return att_b;
		else if (att_a.power <= power)
			return att_a;
		else
			return new attack(type, (short)0,(short)0);
	}
}
class attack
{
	public short rdamage;
	public short power;
	public char type;
	public attack(char type, short power, short rdamage)
	{
		this.type = type;
		this.power = power;
		this.rdamage = rdamage;
	}
}
