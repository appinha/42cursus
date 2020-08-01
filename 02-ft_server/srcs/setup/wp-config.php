<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'user42' );

/** MySQL database password */
define( 'DB_PASSWORD', 'user42' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'yEK:Z.h-s`o3S3JB3x3maFmamAvaAphQP=<#TP?Km(]y)qYpu4J:mK~;guV0A/JG');
define('SECURE_AUTH_KEY',  'ENolpGlR+7@2!^#W~a*er>|_u3|Vf}:pX,r~Y-5E> f-emd+7svh7ic5~n#tNzMJ');
define('LOGGED_IN_KEY',    'E2@ONFBqu5ym#|H8X?p=7kh.O}-]78FRB7iLdk5B|a&u*Gf > pOdY2970M9WSu]');
define('NONCE_KEY',        '-5d#>b-xWAilVJQJuN! M+{KHO%v0/HDkAa&k;+UAm6+wP#y.u#{Q+#5Q;9hs[@i');
define('AUTH_SALT',        '!3O2;0:8r<L2`=_]%,L;jkH,&7G_hX7j*KD-+~4Z+N|Ka6)BT/9PpKvrt;Owf+W%');
define('SECURE_AUTH_SALT', 'iXYV(--YP[AFsi>A[/Z1Z-KQ$b?V8f|EV{=Lo5(=YMDb++[ET/hu0JRKG4I%~nLq');
define('LOGGED_IN_SALT',   'J~8JC[~xr0*!RXt{:@{1S@mR2|3L>@eaiy(*.fm^7Y4fb+z `.CD3B=r$}R+vUD;');
define('NONCE_SALT',       'v4(]?;u4dks-rcY+AP]j[:7BsE(Eo?ri?PXB.mh]Ul!SVZ:Fv:gk+m9-Z/Z?3Y-w');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
