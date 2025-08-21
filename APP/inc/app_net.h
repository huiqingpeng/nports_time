





/* State enumeration for TCP connections */
typedef enum
{
	STATE_INIT = 0,
	STATE_TCP_OPEN,
	STATE_TCP_CONN,
	STATE_TCP_CLOSE,
	STATE_TCP_WAIT,
	STATE_RW_DATA,
	STATE_MAX
} sock_state_enum;
