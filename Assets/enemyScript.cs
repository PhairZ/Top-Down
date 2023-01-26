using UnityEngine;

public class enemyScript : MonoBehaviour, Interactable
{
    [SerializeField] int health = 100;
    void Start()
    {
        
    }

    void Update()
    {
        
    }

    public void getdamaged(int damage) 
    {
        health -= damage;
        if(health <= 0)
        {
            Destroy(gameObject);
        }
        Debug.Log("im ded");
    }
}
