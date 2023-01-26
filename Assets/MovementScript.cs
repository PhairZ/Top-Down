using UnityEngine;

public class MovementScript : MonoBehaviour
{
    private Rigidbody2D rb;
    [SerializeField] private float speed;
    [SerializeField] private Transform overlapposition;
    [SerializeField] private float areaofcirlce;
    [SerializeField] private LayerMask whatisinteractable;
    Collider2D[] colliders;
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        Vector2 move = new Vector2(horizontal, vertical);

        rb.velocity = move.normalized * speed;


        if (Input.GetButtonDown("Attack"))
        {
            colliders = Physics2D.OverlapCircleAll(overlapposition.position, areaofcirlce, whatisinteractable);
            attack();
        }
    }

    private void attack() 
    {
        for(int i = 0; i < colliders.Length; i++)
        {
            colliders[i].GetComponent<Interactable>().getdamaged(10);
        }
    }

    private void OnDrawGizmos()
    {
        Gizmos.color = Color.black;
        Gizmos.DrawWireSphere(overlapposition.position, areaofcirlce);
    }
}
